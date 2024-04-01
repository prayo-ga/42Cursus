import sys

matriz = [ # Primer puntero
    [1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], # Segundo puntero
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1], # Segundo puntero
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1], # Segundo puntero
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1], # Segundo puntero
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1], # Segundo puntero
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1], # Segundo puntero
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], # Segundo puntero
]

print("Primer Puntero: " + str(matriz[0]))
print("Segundo Puntero: " + str(matriz[0][0]))

print("Length Matriz: " + str(len(matriz)))
print("Length 1era Matriz: " + str(len(matriz[0])))

print(sys.argv)