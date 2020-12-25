print('Programa para calcular el índice de masa corporal\n')

peso = float( input('Ingrese su peso [Kg]: ') )

altura = float( input('Ingrese su altura [cm]: ') )
altura /= 100.0

imc = peso / (altura**2)

print(f'\nSu índice de masa corporal es {round(imc, 2)}')

if imc<18.5:
    print('Estás muy flaco')
elif imc<25:
    print('Estás apenas')
elif imc<30.0:
    print('Estás gordo')
else:
    print('Estás obeso')


