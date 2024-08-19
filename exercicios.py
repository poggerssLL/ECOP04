n1 = int(input("Insira o primeiro valor:"))
n2 = int(input("Insira o segundo valor:"))
if n1>n2:
    print("n1 maior")
elif n2>n1:
    print("n2 maior")
elif n2==n1:
    print("Numeros iguais")
if n2==0:
    print("não é possivel dividir por 0")
else:
    print("divisao é {}". format(n1/n2))
print("a soma é {}".format(n1+n2))
print("a subtração é {}". format(n1-n2))
