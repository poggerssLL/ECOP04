minimo =  int(input("Digite o comeco do incremento"))
maximo = int(input("Digite o final do incremento"))
x = minimo
print("indo de 1 em 1")
for x in range(minimo, (maximo+1)):
    print(x)
print("indo de 2 em 2")
for x in range(minimo, (maximo+1), 2):
    print(x)
print("Indo ao contrario de 1 em 1")
for x in range (maximo, (minimo-1),-1):
    print(x)
print("Indo ao contrario de 2 em 2")
for x in range (maximo, (minimo-1),-2):
    print(x)