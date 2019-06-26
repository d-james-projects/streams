from streamsx.topology.topology import Topology
import streamsx.topology.context
import json
import time
from streamsx.topology import schema

def Observations():
  while True:
    jsonStr = '''{"patientId":"patient-1", "device":{"id":"VitalsGenerator",      "locationId":"bed1"}, "readingSource": {"id":123, "deviceId":"VitalsGenerator", "sourceType":"generated"}, "reading": {"ts": 605, "uom":"bpm", "value":82.56785326532197, "readingType": {"code":"867-4", "system":"streamsx.health/1.0"}}}'''
    dictObj = json.loads(jsonStr)
    time.sleep(1)
    yield dictObj

def main():
    topo = Topology("patient_data")
    #patientData = topo.source(Observations)
    patientData = topo.subscribe('ingest-beacon', schema.CommonSchema.Json)

    heartRate = patientData.filter(lambda tuple: (tuple['reading']['readingType']['code']=='8867-4'))

    heartRate.sink(print)
    streamsx.topology.context.submit("DISTRIBUTED", topo)

if __name__ == '__main__':
    main()

