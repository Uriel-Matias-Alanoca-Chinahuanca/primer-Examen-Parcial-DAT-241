from multiprocessing import Pool

def terminosSerie(i):
    return 2 * (i + 1)

if __name__ == "__main__":
    N=int(input("ingresar el numero de terminos de la serie: "))
    M = int(input("ingresar el numero de procesos: "))
    with Pool(processes=M) as pool:
        terms = pool.map(terminosSerie, range(N))

    print("Serie generada:", ' '.join(map(str, terms)))