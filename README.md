  On Windows:

  Navitage to 

    C:\Program Files\mosquitto> 

  Run
    mosquitto.exe -c ..\..\Users\brenden\my_mosq_config.conf -v

    This starts up the server
  

  On Linux

  Navigate to
  /var/snap/mosquitto/common

  Publisher

  Syntax
    mosquitto_pub -h {IP of computer running broker } -t '{topic}' -m '{msg}'

  Example
    mosquitto_pub -h 192.168.1.224 -t 'snap/example' -m "msg"

  Subscriber

  Syntax
    mosquitto_sub -h {IP of computer running broker } -t

  Example
    mosquitto_sub -h 192.168.1.224 -t 'snap/example'

"""
To run on Windows:

cd (mqtt_cmd) C:\Users\brenden\Documents\Arduino\Dynamic_Mesh_Network\scripts>
workon mqtt_cmd
"""