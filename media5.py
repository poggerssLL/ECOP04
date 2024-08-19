from random import randint
list = []
tamanho = int(input("Digite o tamanho da lista"))
maxi = int(input("Digite o maximo do numero"))
mini = int(input("Digite o minimo"))
for x  in range(tamanho):
    #list.append(int(input("Numero {} = ".format(x+1))))
    list.append(randint(mini,maxi))
    print(list[x])
media = sum(list)/len(list)
print("A média é {} ".format(media))
print("A soma é {} ".format(sum(list)))