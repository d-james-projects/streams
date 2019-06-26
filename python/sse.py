
from streamsx.topology.topology import Topology
import streamsx.topology.context

from sseclient import SSEClient

class SSEReader(object):
    """
    Read Server-sent events.
    Includes checkpointing/consistent region support
    so that recovery from a checkpoint starts at the last
    saved identifier.

    Uses the sseclient https://pypi.org/project/sseclient/

    Server-sent events: https://en.wikipedia.org/wiki/Server-sent_events
    """
    def __init__(self, url):
        self.url = url
        self.client = None
        self.last_id = None

    def __enter__(self):
        """
        Create the SSEClient.
        Called when (re)starting or recovering from a checkpoint.
        """
        self.client = SSEClient(self.url, last_id = self.last_id)

    def __exit__(self, exc_type, exc_value, traceback):
        self.client = None

    def __call__(self):
        # SSEClient is an iterator of events.
        return self.client

    def __getstate__(self):
        # Only checkpoint the URL and last_id maintained by the client.
        # The actual client cannot be checkpointed (pickled).
        return {'url':self.url, 'last_id':self.client.last_id if self.client else None}

         
def main():
    topo = Topology("WikipediaSSE")
    topo.add_pip_package('sseclient')

    # See https://wikitech.wikimedia.org/wiki/Event_Platform/EventStreams
    wiki_url = 'https://stream.wikimedia.org/v2/stream/recentchange'
    events = topo.source(SSEReader(wiki_url), name='WikiRecentChanges')

    # Only pass through events with data.
    events = events.filter(lambda event : event.data, name='NonEmptyEvents')

    # extract the data as strings
    events = events.map(lambda event : event.data, schema=str, name='EventData')

    events.sink(print)

    streamsx.topology.context.submit("STANDALONE", topo)

"""
    ve = events.view(name="SSEvents", sample_size=20)
    
    j = streamsx.topology.context.submit("STANDALONE", topo)

    print('Server-sent events from ', wiki_url)
    ve.start_data_fetch()
    print(ve.fetch_tuples(max_tuples=10, timeout=60))
    ve.stop_data_fetch()
"""

if __name__ == '__main__':
    main()
