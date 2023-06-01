import serial
import time
import serial.tools.list_ports

all_ports = serial.tools.list_ports.comports()
avl_port = str(all_ports[0].device)
# print(avl_port)

arduino = serial.Serial(
        port = avl_port,
        baudrate = 115200,
        bytesize = serial.EIGHTBITS, 
        parity = serial.PARITY_NONE,
        stopbits = serial.STOPBITS_ONE, 
        timeout = 1,
        xonxoff = False,
        rtscts = True,
        dsrdtr = True,
        writeTimeout = 2
)
arduino.flush()

while True:
    try:
        
        arduino.flush()
        # string = str(n)+"\n"
        # arduino.write(string.encode())

        api = input("Throttle/Break/Steer/Reverse: ")
        # Break = input("Break: ")
        # reverse = input("Reverse: ")
        # steer = input("Steer: ")
        # l = [throttle,Break,reverse,steer]
        # parameters_string = ','.join(str(x) for x in l)
        # arduino.write(parameters_string.encode())
        arduino.write(api.encode())
        # data = arduino.readline()
        # if data:
        #     print(data)
        time.sleep(1)
    except Exception as e:
        print(e)
        arduino.close
    arduino.flush()
