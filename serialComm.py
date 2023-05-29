import serial
import time

arduino = serial.Serial(
        port = "/dev/ttyACM0",
        baudrate = 9600,
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
# n = 0
# string = ""
while True:
    try:
        
        arduino.flush()
        # string = str(n)+"\n"
        # arduino.write(string.encode())
        n = input()
        arduino.write(n.encode())
        data = arduino.readline()
        if data:
            print(data)
        time.sleep(1)
    except Exception as e:
        print(e)
        arduino.close
    arduino.flush()
    # n+=5