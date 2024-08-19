def validacao(a,b,c):
    if a+b >= c and b+c>= a and a+c >= b:
        return True
    else:
        return False
def equilatero(a,b,c):
    if a == c and a == b and b == c:
        return True
    else: 
        return False
def escaleno(a,b,c):
    if a != c and a != b and c != b:
        return True
    else:
        return False
def isosceles(a,b,c):
    if (a == c and a != b) or (a == b and a!= c31):
        return True
    else: 
        return False

lado_a = int(input("Digite o Lado A do triangulo"))
lado_b = int(input("Digite o Lado B do triangulo"))
lado_c = int(input("Digite o Lado C do triangulo"))

if validacao(lado_a, lado_b, lado_c):
    print("O triangulo é valido")
    if equilatero(lado_a, lado_b, lado_c):
        print("O triangulo é equilatero")
    elif isosceles(lado_a, lado_b, lado_c):
        print("O triangulo é isosceles")
    elif escaleno(lado_a, lado_b, lado_c):
        print("O triangulo é escaleno")
else:
    print("Triangulo invalido")