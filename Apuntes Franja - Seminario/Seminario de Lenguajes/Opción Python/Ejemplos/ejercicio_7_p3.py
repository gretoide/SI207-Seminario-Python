#!/usr/bin/env python
# -*- coding: utf-8 -*-

import csv
import PySimpleGUI as sg
import random


GRAFICO_ANCHO = 300
GRAFICO_ALTO = 300

COLUMNA_CANTIDAD = 10
COLUMNA_UNIVERSIDAD = 2


def leer_archivo(nombre):
    cantidades_por_universidad = dict()
    with open(nombre, 'r') as csvfile:
        reader = csv.reader( csvfile, delimiter=',', quotechar='"' )
        next(reader) # Salto la primer linea (encabezado)
        for row in reader:
            universidad = row[COLUMNA_UNIVERSIDAD]
            valor = (int(row[COLUMNA_CANTIDAD]) if row[COLUMNA_CANTIDAD] is not '' else 0)
            if universidad not in cantidades_por_universidad:
                cantidades_por_universidad[universidad] = valor
            else:
                cantidades_por_universidad[universidad] += valor
    return cantidades_por_universidad




def ordenar_lista_universidades(valores):
    return(sorted(valores, key=lambda y: y[1], reverse=True))



def calcular_proporcion(valores):
    valor_maximo = max(valores, key=lambda x: x[1]) [1] # Devuelve tupla con el maximo: 0 universidad, 1 valor
    tamano_maximo = 75 # Limitamos a 75 pixeles como el tamano mas grande.
    return tamano_maximo / int(valor_maximo)
    


def dibujar(valores, grafico):
    proporcion = calcular_proporcion(valores)

    for valor in valores:
        tamano = proporcion * valor[1]
        posicion = (random.randrange(GRAFICO_ANCHO), random.randrange(GRAFICO_ALTO))
        grafico.DrawCircle( posicion, tamano, fill_color='black', line_color='white')



def actualizar_listado(listbox, lista):
    listbox.Update(map(lambda x: "{}: {}".format(x[0], x[1]), lista_cantidades))


# Programa principal

main_layout = [
    [ sg.Text('Archivo') ],
    [ sg.Input(), sg.FileBrowse(), sg.OK(), sg.Button('Cancelar') ],
    [ 
        sg.Listbox( values=[], key='universidades', size= (60,10) ),
        sg.Graph( canvas_size=(GRAFICO_ANCHO, GRAFICO_ALTO), graph_bottom_left=(0,0), graph_top_right=(GRAFICO_ANCHO, GRAFICO_ALTO), background_color='red', key='grafico' )
    ],
    [ sg.ReadButton('Ordenar', key='boton_ordenar', disabled=True) ]
]

window = sg.Window('Ejercicio 7 (Práctica 3)').Layout(main_layout)
lista_cantidades = []
lei_archivo = False

while True:
    event, values = window.Read()

    if event is None or event == 'Cancelar':
        break

    if event is event == 'OK':

        window.FindElement('boton_ordenar').Update(disabled=False)
        lei_archivo = True

        lista_cantidades = leer_archivo(values[0]).items()

        dibujar( lista_cantidades, window.FindElement('grafico') )
        actualizar_listado( window.FindElement('universidades'), lista_cantidades)
        

    if event == 'boton_ordenar' and lei_archivo:

        lista_cantidades = ordenar_lista_universidades(lista_cantidades)
        actualizar_listado( window.FindElement('universidades'), lista_cantidades)

