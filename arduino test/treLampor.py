#importerar tid och serial cominication
import time
import serial


#gör en variabel så jag inte behöver skriva denna stora kod varja gång jag ska skciak något
ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)

#vänta 2 sekuner så arduino hinnar att starta
time.sleep(2)

#förklarar hur man stänger program
print("tryck ctrl(controll) och C för att stänga av program")

#gör en dictionery
komando ={
    "röd av": b'0',
    "röd på": b'1',
    "grön av": b'2',
    "grön på": b'3',
    "blå av": b'4',
    "blå på": b'5',
    "alla av": b'8',
    "alla på": b'9',
}



#testar en loop och om man klickar ctrl och C stängs den
try:

    #en loop som gör så programet körs om och om igen
    while True:

        #gör en variabel av svaret på frågan från använderen
        #strip tar bort onädiga mellan slag. och lower gör allt till små bokstäver
        status=input("vilken lampa ska på eller av? t.ex röd på: ").strip().lower()

        #kollar om variabeln status finns i komando dictionery
        if status in komando:
            #skickar till arduino genom serial översätningen av status genom dictionery
            ser.write(komando[status])

        #om den inte finns i dictionery så printar den detta
        else: print("okänt komando. försök igen.(t.ex röd på) ctrl + C för att stänga")
        
except KeyboardInterrupt:
    print ("\nstänger port")
    ser.close()