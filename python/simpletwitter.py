from streamsx.topology.topology import Topology
import streamsx.topology.context
import json
import time
from streamsx.topology import schema
from pubnub.callbacks import SubscribeCallback
from pubnub.enums import PNStatusCategory
from pubnub.pnconfiguration import PNConfiguration
from pubnub.pubnub import PubNub
import time
#import json
import re

output = []
pnconfig = PNConfiguration()
pnconfig.subscribe_key = 'sub-c-78806dd4-42a6-11e4-aed8-02ee2ddab7fe'
 
pubnub = PubNub(pnconfig)  

class MySubscribeCallback(SubscribeCallback):
    def presence(self, pubnub, presence):
        pass  # handle incoming presence data
 
    def status(self, pubnub, status):
        pass

    def message(self, pubnub, message):
        global output
        values = {}
        values['text'] = re.sub(r'[^\x00-\x7f]',r'',message.message['text'][0:100])
        # write record to a list
        output.append(values)

def GetPublished():
  while True:
    # start the capture of published data
    global output
    output.clear()
    yield iter(output)

def main():
    global pubnub
    my_listener = MySubscribeCallback()
    pubnub.add_listener(my_listener)    
    pubnub.subscribe().channels('pubnub-twitter').execute()    
    topo = Topology("simple_twitter")
    topo.add_pip_package('pubnub')
    Data = topo.source(GetPublished())

    Data.sink(print)

    streamsx.topology.context.submit("STANDALONE", topo)

if __name__ == '__main__':
    main()

