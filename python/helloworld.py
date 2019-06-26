from streamsx.topology.topology import Topology
import streamsx.topology.context
import random

def readings():
    while True:
        yield random.gauss(0.0, 1.0)

def main():
    topo = Topology("temperature_sensor")
    source = topo.source(readings)
    source.sink(print)
    streamsx.topology.context.submit("STANDALONE", topo)

if __name__ == '__main__':
    main()

