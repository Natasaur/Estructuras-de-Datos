# Crear un archivo .dat y escribir datos en él
with open('cuentas.dat', 'w') as file:
    file.write("Este es un archivo de datos.\n")
    file.write("Puede contener cualquier tipo de información.")
