# Instruções para abertura do projeto

Utilizando o programa KiCad (Projeto feito com a versão 8) basta pressionar "Arquivo" -> "Desarquive o Projeto," selecionar o arquivo kicad_project.zip e a pasta de destino. Então basta pressionar "Arquivo" -> "Abrir o Projeto" para abrir. Agora podem ser vistos os arquivos arquivos de esquemático e de layout da PCB.

Alguns componentes foram utilizados que não fazem parte da biblioteca padrão do KiCad, eles estão na pasta components_kicad e podem ser importados no KiCad utilizando o [tutorial](https://www.snapeda.com/about/import/#). Para a visualização dos modelos 3D, é necessário selecionar os modelos presentes na mesma pasta (arquivos .step), para cada componente. Para isso basta abrir o diagrama do layout da PCB, clicar com o direito no componente e clicar em "Propriedades", então abrir a aba "Modelos 3D" e selecionar o caminho correto. Isto precisa ser feito para o conector da antena GPS e o chip GPS NEO-6M.
