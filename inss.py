ganho = int(input("Digite o quanto voce ganha por hora: "))
horas= int(input("Digite as horas trabalhadas no mes: "))
salario = ganho*horas
inss = (salario*8)/100
renda =  (salario*11)/100
sindicato = (salario*5)/100
liquido = salario - (inss + renda + sindicato)
print("Seu salario bruto é {} Reais".format(salario))
print("Voce paga {} Reais para o INSS". format(inss))
print("Voce paga {} Reais para o sindicato". format(sindicato))
print("Voce paga {} Reais de Imposto de Renda". format(renda))
print("Seu salario liquido é {}". format(liquido))