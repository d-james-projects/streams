from streamsx.topology.topology import Topology
import streamsx.topology.context
import random

def hwSource():
    while True:
        yield 'Hello world'

def main():
    topo = Topology("hello_world")
    source = topo.source(hwSource)
    source.sink(print)
    streamsx.topology.context.submit("STANDALONE", topo)

if __name__ == '__main__':
    main()

