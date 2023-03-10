import PySimpleGUI as sg
from pattern.es import INFINITIVE, conjugate, tag
from collections import Counter

layout = [[sg.Text('Ingrese la frase:')],  
          [sg.Multiline(do_not_clear=True, key='frase'), sg.Multiline('', key='resultado')],  
          [sg.Button('Mostrar'), sg.Button('Salir')]]  

window = sg.Window('Ejercicio 12').Layout(layout)  

def ej12(frase):
	#frase = 'Este es un párrafo de prueba. El verbo ser, será el mas utilizado. El otro será crear, por eso se creó la oración de esta manera. Por último, se creará esta oración que posee el tercer verbo: poseer. Nada más que decir.'
	verbos = []
	for value, key in tag(frase):
		if key == "VB":
			verbos.append(conjugate(value, INFINITIVE))
	c = Counter(verbos)
	return c.most_common(3)

while True:
  event, values = window.Read()
  if event is None or event == 'Salir':  
      break  
  if event == 'Mostrar':  
      resultado = ej12(values['frase']) 
      window.FindElement('resultado').Update(resultado)

window.Close()
