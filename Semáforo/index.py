import serial
arduino = serial.Serial('COM4',9600)
while True:
    try:
        leitura = arduino.readline().decode().strip()
        if leitura:
            temperatura = float(leitura)
            if temperatura < 10.5:
                arduino.write(b'B')
                print(f'A temperatura é de {temperatura}ºC e está abaixo do esperado.')
            elif temperatura >= 10.5 and temperatura < 11.5:
                arduino.write(b'V')
                print(f'A temperatura é de {temperatura}ºC e está em sua normalidade.')
            else:
                arduino.write(b'R')
                print(f'A temperatura é de {temperatura}ºC e está acima do esperado.')
    except KeyboardInterrupt:
        break
    except Exception as e:
        print('Ocorreu um erro:', e)