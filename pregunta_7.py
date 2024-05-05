import multiprocessing

def calcularSumatoriaPI(inicio, fin):
    suma = 0
    for i in range(inicio, fin):
        termino = (-1) ** i / (2 * i + 1)
        suma += termino
    return suma

if __name__ == "__main__":
    nt = 1000000  
    procesadores = 8  
    pool = multiprocessing.Pool(processes=procesadores)
    NTProcesador = nt // procesadores
    intervalos = []
    i = 0
    for _ in range(procesadores):
        f = i + NTProcesador
        intervalos.append((i, f))
        i = f
        
    intervalos[-1] = (intervalos[-1][0], nt)
    r = pool.starmap(calcularSumatoriaPI, intervalos)
    st = sum(r)
    print("Valor aproximado de Pi:", st*4)
