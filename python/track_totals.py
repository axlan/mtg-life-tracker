import time
from datetime import datetime
import json
import sys

import paho.mqtt.client as mqtt

topic = 'life_counters/{client_id}/totals_json'
server = '192.168.1.110'

# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))

    # Subscribing in on_connect() means that if we lose the connection and
    # reconnect then subscriptions will be renewed.
    for client_id in userdata['client_ids']:
        client.subscribe(topic.format(client_id=client_id))

# The callback for when a PUBLISH message is received from the server.
def on_message(client, userdata, msg):
    client_id = msg.topic.split('/')[1]
    decoded = json.loads(msg.payload)
    decoded.insert(0, time.time())
    print(client_id, decoded)
    userdata['fds'][client_id].write(','.join([str(i) for i in decoded]) + "\n")

def main():

    if len(sys.argv) < 2:
        print('usage: python track_totals.py CLIENT_ID1 CLIENT_ID2 ...')
        exit(1)
    client_ids = sys.argv[1:]

    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    fds = {}
    for client_id in client_ids:
        fds[client_id] = open(f'out/life_tracker_{timestamp}_{client_id}.csv' ,'w')
    userdata = {
        'fds': fds,
        'client_ids': client_ids
    }

    client = mqtt.Client(userdata=userdata)
    client.on_connect = on_connect
    client.on_message = on_message

    client.connect(server, 1883, 60)

    # Blocking call that processes network traffic, dispatches callbacks and
    # handles reconnecting.
    # Other loop*() functions are available that give a threaded interface and a
    # manual interface.
    client.loop_forever()


if __name__ == "__main__":
    main()
