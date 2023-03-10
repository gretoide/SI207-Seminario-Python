#ver si es multiplo de 2, 3 o 5

n = int(input("ingrese un numero ->"))

if(n % 2 == 0):
    print(n," es multiplo de 2")
if(n % 3 == 0):
    print(n," es multiplo de 3")
if(n % 5 == 0):
    print(n," es multiplo de 5")
else: print("metiste un numero de mierda, no es multiplo de nada")