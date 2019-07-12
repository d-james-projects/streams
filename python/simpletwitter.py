import time
from pubnub.callbacks import SubscribeCallback
from pubnub.enums import PNStatusCategory
from pubnub.pnconfiguration import PNConfiguration
from pubnub.pubnub import PubNub
import re
import sys

class MySubscribeCallback(SubscribeCallback):
    def presence(self, pubnub, presence):
        pass  # handle incoming presence data
 
    def status(self, pubnub, status):
        pass

    def message(self, pubnub, message):
        value = re.sub(r'[^\x00-\x7f]',r'',message.message['text'][0:100])
        # write record
        print('\"{}\"'.format(value))

def main():
    pnconfig = PNConfiguration()
    pnconfig.subscribe_key = 'sub-c-78806dd4-42a6-11e4-aed8-02ee2ddab7fe'
 
    pubnub = PubNub(pnconfig)  
    my_listener = MySubscribeCallback()
    pubnub.add_listener(my_listener)    

    while True:
      try:
        pubnub.subscribe().channels('pubnub-twitter').execute()    
        time.sleep(1)
        pubnub.unsubscribe_all()
        time.sleep(1)
      except KeyboardInterrupt:
        pubnub.remove_listener(my_listener)
        return sys.exc_info()

if __name__ == '__main__':
    exc = main()
    sys.exit(0)

