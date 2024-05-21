# `Monitor de Desempenho de Jogadores de Tênis`
# `TennisTracker`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Introdução ao Projeto de Sistemas Embarcados*, 
oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).


|Nome  | RA | Curso|
|--|--|--|
| Nathan Shen Baldon  | 242448 | Eng. Elétrica|
| Gabriel Buzzi Sanches  | 256389  | Eng. Elétrica|


## Descrição do Projeto

O Tênis é conhecido por ser um esporte difícil de se praticar pela exigência de cordenação física e agilidade nos movimentos. Sabendo disso os feedbacks de cada jogada são de extrema importância para quem está aprendendo ou quer melhorar no esporte. Pensando nisso nosso objetivo é entregar esses feedbacks tirando proveito da mecânida dos movimentos da raquete do jogador durante uma partida, assim excluindo também qualquer viés devido a um observador terceiro (professor ou treinador) e ainda oferencendo uma base fixa para comparação dos resultados. Para isso um sistema eletrônico embarcado será projetado para ficar fixado na raquete do jogador enquanto ele prática o esporte aquisitando e armazenando dados variados que posteriormente podem ser analisados em cumputador. Inicialmente qualquer processamento em tempo real é deixado de lado, focando apenas na aquisição dos dados, mas o projeto do sistema irá considerar como uma medida de escalabilidade a capacidade de realizar processamentos em tempo real e retornar respostas mesmo durante a jogatina.  

##### Potenciais usuários
- Jogadores de tênis (desde iniciantes até profissionais) que desejam acompanhar sua jornada e desenvolvimento no esporte.
- Treinadores que desejam coletar dados para validar seu método de treinamento.
- Uso pela mídia e entidades do esporte em partidas oficiais para levantamento de estatísticas.
  
##### Valor econômico associado  

O dispositivo poderia ser vendido para qualquer pessoa interessada em monitorar seu desempenho no esporte Tênis.

## Descrição Funcional

### Funcionalidades
- **Fixar na raquete**: o sistema deve poder ser afixado na raquete de tênis.
- **Armazenar os dados aquisitados**: o sistema deve ser capaz de salavar na memória os dados dos sensores.
- **Medir a velocidade da raquete**: o sistema deve adquirir dados que permitam estimar velocidade.
- **Medir a intensidade das colisões com a bolinha**: o sistema deve adquirir dados que permitam estimar a intensidade de colisões com a bola.
- **Medir o ângulo com a horizontal da raquete**: o sistema deve adquirir dados que permitam estimar o ângulo da raquete em relação ao solo.
- **Interface para controlar quando começar quando parar aquisição**: deve ser possível controlar quando interromper as medições.
- **Interface para exportar os dados**: deve ser possível exportar os dados para análise externa.
- **Peso reduzido**: o sistema deve ser leve, para que não influencie nas jogadas.
- **Sinalizar o nível de bateria**: o sistema deve ser capaz de exibir o nível da bateria.
- **Armazenamento de energia (bateria)**: o sistema deve ser capaz de funcionar sem necessidade de cabos de energia.

### Funcionalidade de análise:
Uma vez que o dados forem aquisitados, via software poderemos executar:
- Contar o número de golpes
- Medir o tempo jogado
- Estimar a qualidade dos golpes
- Identificar golpes
- Encontrar correlações entre a varáveis medidas e desempenho na partida
- Avaliar o rendimento físico do atleta
- Avaliar caracteristicas dos golpes que resultam em pontos na partida

### Configurabilidade
- Aquisição
- Carregamento
- Carregamento + Transferência de Dados

### Eventos
|Eventos  | 
|--|
| Ligar (botão on/off)  | 
| Desligar (botão on/off)  |
| USB com interface de dados conectado |
| USB de alimentação conectado | 

### Tratamento de Eventos

|Eventos  | Tratamento  | 
|--|--|
|Ligar (botão on/off)  | Iniciar medições de grandezas (posição, velocidade, aceleração, etc.) (periódico com taxa de amostragem) + ativar LED RGB em verde  |
| Desligar (botão on/off)  | Interromper as medições e o fornecimento de energia + apagar LED RGB  |
| USB com interface de dados conectado  |  Desligar os sensores, carregar a bateria e ligar o modo de comunicação de dados + LED RGB em azul |
| USB de alimentação conectado |  Desligar os sensores e carregar a bateria + LED RGB em vermelho|

## Descrição Estrutural do Sistema

Atuadores:
- Display indicador de bateria
- LED RGB

Sensores:
- Acelerômetro e Giroscópio [MPU-6050](https://www.makerhero.com/produto/acelerometro-e-giroscopio-3-eixos-6-dof-mpu-6050/?utm_source=google&utm_medium=organic&utm_campaign=shopping&utm_content=surfaces_across_google&gad_source=1&gclid=CjwKCAjwtqmwBhBVEiwAL-WAYQ2EM5FQUUMtuxIyKFbXBxsoUhK2dI_2Ud5VmFDbftmgO3FnrXPz_hoCWkoQAvD_BwE#tab-blogrelacionados)

Botões:
- Botão ON/OFF

Comunicação:
- Comunicação via cabo USB

### Diagrama Estrutural:

[![diagrama_estrutural.svg editável](/projetos/tennistracker/diagrama_estrutural.svg)](https://app.diagrams.net/?libs=general;#Hshen-n%2Fea075-2024.1%2Fmain%2Fprojetos%2Ftennistracker%2Fdiagrama_estrutural.svg#%7B%22pageId%22%3A%2290a13364-a465-7bf4-72fc-28e22215d7a0%22%7D)

### Diagrama de Estados:

[![diagrama.svg editável](/projetos/tennistracker/diagrama.svg)](https://app.diagrams.net/#Hshen-n%2Fea075-2024.1%2Fmain%2Fprojetos%2Ftennistracker%2Fdiagrama.svg#%7B%22pageId%22%3A%2242789a77-a242-8287-6e28-9cd8cfd52e62%22%7D)

| Estado  | Função | 
|--|--|
| Desligado  | Neste estado, o produto está totalmente inativo: o LED fica apagado, o sensor fica desabilitado e o microcontrolador entra em modo de baixa potência. A saída deste estado pode se dar em dois casos: (i) se o botão for pressionado, indicando que deseja-se ativar o produto para aquisição de dados; (ii) caso um cabo USB seja conectado, para carregamento ou transferência de dados |
| Aquisição  | Neste modo, o dispositivo está fazendo sua atividade-fim: adquirindo dados do sensor de movimento e salvando em uma unidade de memória. Para indicar que está ativo, o LED RGB fica verde. E, para mostrar o nível de bateria, o indicador de bateria também fica ligado. Para sair do estado de aquisição, o botão deve ser pressionado, o que leva o produto para o estado 'desligado'  |
| Carregamento  | Neste estado, um cabo USB está conectado ao produto e a carga da bateria é realizada. Para indicar isto, o led RGB fica em vermelho e o indicador de bateria é atualizado conforme a carga aumenta. |
| Carregamento + transferência de dados | Neste estado, um cabo USB de dados deve estar conectado ao dispositivo. Nele, os dados da unidade da memória são transmitidos pelo canal USB. Para sinalizar a comunicação, o led RGB fica em azul e, para indicar o carregamento, o indicador de bateria é atualizado conforme a carga aumenta. |


## Referências
> Motion Processing Unit – MPU9250 for RTPT https://paulplusx.wordpress.com/2016/03/04/rtpts_mpu/
> Arduino and MPU6050 Accelerometer and Gyroscope Tutorial https://howtomechatronics.com/tutorials/arduino/arduino-and-mpu6050-accelerometer-and-gyroscope-tutorial/
