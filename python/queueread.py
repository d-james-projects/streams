import time
import sys
import pprint
import json

import stomp

class MyListener(stomp.ConnectionListener):
    def on_error(self, headers, message):
        print('received an error "%s"' % message)
    def on_message(self, headers, message):
        print('received a message')
        pprint.pprint(message)

host = "localhost"
port = 61613

conn = stomp.Connection(host_and_ports = [(host, port)])
#conn.set_listener('', MyListener())
conn.start()
conn.connect('admin', 'password', wait=True)

conn.subscribe(destination='/queue/MapQueue', id=10, ack='auto', headers={'transformation' : 'jms-map-json'})


#conn.send(body=' '.join(sys.argv[1:]), destination='/queue/test')

mydict = {"map":{"entry":[{"string":"passengerCnt","int":999},{"string":["carrier","Japan Airlines"]},{"string":"gateNumber","int":999},{"string":["model","Boeing 757"]},{"string":["arrivingFrom","HND"]},{"string":"tarmacId","int":19}]}}

myjson = [{"string":"passengerCnt","int":999},{"string":["carrier","Japan Airlines"]},{"string":"gateNumber","int":999},{"string":["model","Boeing 757"]},{"string":["arrivingFrom","HND"]},{"string":"tarmacId","int":19}]

conn.send(body=json.dumps(myjson), destination='/queue/MapQueue', headers={'transformation' : 'jms-map-json'})
 
while True:
  time.sleep(1)

conn.disconnect()
