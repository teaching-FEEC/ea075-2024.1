# `OptiSort: Classificador de objetos`
# `OptiSort: Object classifier`
## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Introdução ao Projeto de Sistemas Embarcados*, 
oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).
|Nome  | RA | Curso|
|--|--|--|
| Henrique Stumm Rocha  | 239694  | Eng. Elétrica|
| Melvin Gustavo Maradiaga Elvir  | 185068  | Eng. Elétrica|

## Descrição do Projeto
### Contexto Gerador e Motivação
Todo ano a ONU realiza um estudo, nomeado _Food Waste Index Report_, onde reportam a produção global de alimento e analizam o desperdiço alimentar gerado nos níveis de distribuição e consumidor final. Na versão mais recente [1] apresentaram-se os resultados oriundos de uma pesquisa realizada no Rio de Janeiro (pg.20-21) coletando dados de 102 lares distintos de díversos posicionamentos socio-econômicos. Nele, reportaram que um 39% do desperdiço era de alimentos ainda comestíveis, e estimaram uma produção anual de 77kg/capita de resíduo desta classe (classe II).  
Agora, olhando para a região de São Paulo, em 2022 foi publicado um artigo na revista Sustainability [2] fornecendo métricas de resíduo alimentar oriundo de feiras dentro da cidade, estimando uma produção de 27,9 kg de desperdiço por barraca. Estes dados, ao serem extrapolados ao periodo de um ano em todas as barracas da cidade, oferece uma primeira estimativa da geração de desperdiço na cidade, umas 59.300 toneladas ao ano, com uma parcela não desprezível sendo material ainda comestível.  
Com esses dados espera-se ter apontado que Brasil gera bastante desperdiço alimentar que, ainda com iniciativas auxiliando no seu aproveitamento (como o banco de alimentos dentro dos municípios), precisa ser contabilizado e administrado de formas mais eficientes para permitir o descarte (ou reuso) apropríado. Por conta disso, estamos propondo um projeto que consiga auxiliar na identificação, o registro e acompanhamento de desperdiço alimentar dentro dos principais centros de coleta de resíduo alimentar.

### Projeto
O OptiSort tem como objetivo realizar a classificação do desperdiço em centros de coleta alimentar (como bancos de alimentos) mediante a utilização de técnicas avançadas de visão computacional e aprendizado de máquina, sendo capaz de armazenar e disponibilizar os dados coletados ao longo da sua operação para o usuario.
Mediante sua implementação espera-se agilizar a classificação alimentar dentro dos locais onde ele for instalado, espera-se diminuir a perda de alimentos oriunda do erro humano dentro da classificação e espera-se apoiar o registro de desperdiço alimentar dentro da cidade.

Atualmente não conseguimos levantar o valor econômico associado ao projeto por conta de ainda estar determinando a escala do protótipo que será desenvolvido e os materiais que serão utilizados para o seu desenvolvimento. Após termos feito isso, será possível realizar uma estimativa inicial.

## Descrição Funcional
### Funcionalidades
O OptiSort, como dito anteriormente, é um sistema de classificação automática para linhas de produção com foco na indústria alimentícia, mas tendo aplicações nas industrias farmacêuticas, automobilísticas e outras. Sua função principal é garantir a qualidade dos produtos através da identificação, classificação e remoção de itens que não atendam aos padrões de qualidade estabelecidos pelo usuario.

Ele realiza três grandes tarefas:
* **Identificação e classificação:** Reconhece os tipos de frutas que temos inserido na esteira e as separa em categorias, utilizando técnicas de visão computacional e aprendizado de máquina para identificar a qualidade associada a cada uma.
* **Atuação na linha de produção:** Controle de atuadores para remover automaticamente as frutas estragdas da esteira principal, direcionando-as para uma linha secundária para reavaliação ou descarte.
* **Registro:** Monitora o funcionamento do sistema e armazena os dados de qualidade, quantidade e descarte numa base de dados. 

**Exemplo de aplicação:**  
No linha de separação de frutas, o OptiSort:
* Detecta frutas estragadas por visão computacional.
* Empurra as frutas estragadas para fora da esteira principal.
* Direciona as frutas estragadas para uma linha secundária para reavaliação ou descarte.

### Configurabilidade
Para atingir a flexibilidade desejada deste sistema, o OptiSort conta com diversas configurações para atender às necessidades específicas de cada aplicação. Podemos agrupar as suas principais configurações em três grandes grupos:

#### Parâmetros de Identificação:
   - **Tipos de itens:** Definição dos tipos de itens que o sistema deve identificar e classificar. O usuário precisará capturar imagens das frutas que ele precisa Optisort consiga classifcar, colocando imagens de diferentes níveis de qualidade para treinar o classificador com visão computacional. O processo de treinamento deve ser simples e intuitivo e não requerer o uso de programação.
   - **Probabilidade de rejeição:** A saída do classificador visual é um número correspondente à probabilidade de um item ser da categoria rejeitada. O limite de rejeição é a probabilidade a partir da qual o item deve ser identificado e retirado da linha de separação. Por exemplo, se o limite de rejeição for de 0.7, apenas produtos atribuídos com mais de 70% de probabilidade pelo sistema de visão computacional são removidos da esteira.
   - **Número máximo de itens rejeitados abandonados:** No caso de um item rejeitado não ser removido da esteira por fatores externos, o sistema registra esse evento. Se o número de itens rejeitados que passarem pela inspeção passar de uma determinada taxa, a esteira é interrompida

#### Parâmetros de Atuação
   - **Velocidade da esteira:** Ajuste da velocidade da esteira de acordo com o fluxo de produção.
   - **Velocidade máxima do atuador:** Velocidade máxima com que o atuador reage para retirar os itens defeituosos da linha principal. Depende da velocidade da esteira.
   - **Margem de atuação:** Distância máxima do atuador que a fruta precisa ser detectada para que haja o disparo do sistema.

#### Parâmetros de Registro
   - **Regularidade do Monitoramento:** Intervalo de tempo entre cada "monitoramento" do estado atual do dispositivo.

Os parâmetros mais físicos (como sendo os de atuação e alguns de registro) poderão ser configurados de forma dinâmica enquanto a linha de produção está em operação mediante um controlador.

**Exemplo de aplicação**
Na linha de separação de frutas, o sistema OptiSort pode ser configurado para:
* Identificar diferentes tipos de frutas (por exemplo, maçãs, laranjas, bananas).
* Classificar as frutas por qualidade, considerando estragadas aquelas cuja probabilidade for menor de 50%.
* Um segundo depois da fruta estragada ter sido identificada, remover ela da esteira mediante um servomotor.
* Gerar um relatório de produção detalhando o número de frutas processadas e separadas da linha principal.

### Eventos
Ao longo da sua operação definem-se vários tipos de "eventos" que descrevem o comportamento do sistema num determinado instante de tempo.

#### Eventos Periódicos
1. **Aquisição de Imagens:**  
    Periodicidade: _Contínua (7.5 vezes por segundo)._  
    Descrição: _O sistema captura imagens da esteira transportadora prévio a realizar a identificação e classificação dos itens._

2. **Processamento de Imagens:**  
    Periodicidade: _Contínua (7.5 vezes por segundo)._  
    Descrição: _O sistema aplica algoritmos de visão computacional e aprendizado de máquina para identificar os itens de interesse e realizar a análise da sua qualidade._

#### Eventos Não Periódicos:
1. **Atuação na Linha de Produção:**  
    Descrição: _O sistema detecta um item de qualidade baixa na linha principal e ativa os atuadores._

2. **Passagem de item defeituoso para a próxima etapa:**  
    Descrição: _Devido a algum fator externo, como excesso de itens na esteira, o OptiSort não é capaz de remover o item defeituoso a tempo e ele passa para a próxima etapa de produção._

3. **Captação de dados do controlador:**  
   Descrição: _O sistema detecta que houve uma manipulação ao controlador de configuração._
   
4. **Registro de dados de operação:**  
   Descrição: _O sistema armazena os dados de operação da esteira numa base de dados._

5. **Atualizações de Software:**  
    Descrição: _O sistema pode receber atualizações de software para melhorar seu desempenho ou adicionar novas funcionalidades._

### Tratamento de Eventos
Abaixo, detalhamos mais sobre o comportamento do sistema para cada tipo de evento.

#### Eventos Periódicos:
1. **Aquisição de Imagens:** O sistema captura imagens da esteira transportadora mediante uma câmera ligada ao dispositivo controlador. As imagens são armazenadas em um buffer de memória para serem processadas posteriormente.  

2. **Processamento de Imagens:** O sistema aplica algoritmos de visão computacional e aprendizado de máquina para analisar as imagens e identificar os itens. Mediante os pesos internos do modelo de aprendizado de máquina (determinados por prévio treinamento do algoritmo) o dispositivo determina a qualidade dos itens dentro da imagem.

#### Eventos Não Periódicos:
1. **Atuação na Linha de Produção:** Se um item defeituoso for detectado, o sistema aciona um servomotor para removê-lo da esteira. O item defeituoso é direcionado para uma linha secundária para reavaliação ou descarte.

2. **Passagem de item defeituoso para a próxima etapa:** A passagem acidental de um item defeituoso é registrada na memória do sistema. Se o número de itens defeituosos que passarem para a próxima etapa de produção for maior que o parâmetro especificado, o OptiSort interrompe a esteira e solicita avaliação do operador.

3.  **Captação de dados do controlador:** O usuario manipula o controlador vinculado ao dispositivo, gerando uma série de interrupções que permitem a manipulação da interface enquanto o controlador realiza suas tarefas principais. Após ter colocado e confirmado as alterações, o controlador controla a esteira com a nova informação armazenada dentro da sua memória.

4.  **Registro de dados de operação:** Depois de cada registro e classificação de item sendo realizado pela câmera e o controlador, ele vai encaminhando os dados registrados dentro da sua memória a uma base de dados que possa ser visualizada pelo operador.

5. **Atualizações de Software:** Reprogramação do controlador principal acrescentando ou modificando features dentro do funcionamento dele.

## Descrição Estrutural do Sistema
![Diagrama de blocos do sistema](./EA075_Diagram.jpeg)

## Especificações
### Especificação Estrutural
Primeiramente, estabelecemos o microcontrolador STM32H747AII6 (configuração de packaging UFBGA-169) como nossa unidade de computação básica. Como nossa aplicação envolve visão computacional, precisamos de um nível alto de memória e processamento comparado com uma aplicação de software embarcado tradicional. Com custo de &#36;18.74 por unidade [3], ele é competitivo com outras plataformas que seriam usadas para aplicações de IA, como o Raspberry Pi 4 (&#36;35) [5], e está no estado da arte do processamento em baixo consumo de energia, com apenas 2.95 μA de corrente utilizados em Standby, 1 Mbyte de RAM e 480 MHz em uma unidade de processamento 32 bits. A MCU possui sensor de temperatura embutido. [4] 

O microcontrolador tem suporte à interface de comunicação paralela (DCMI) [18], que iremos utilizar para conectar com a câmera que irá monitorar as frutas. Essa interface precisa de 8-14 bits, dependendo do formato de compressão digital de imagens usado pelo sistema. No caso, vamos usar 10 bits de barramento com o formato YCbCr 4:2:2 para a primeira câmera (GC2145 [6]), consumindo 10 entradas digitais de dados, uma de pixel clock (PIXCLK) e duas de sincronização vertical e horizontal da câmera (HSYNC e VSYNC). Também será integrada uma câmera infravermelho ao circuito, para melhorar a qualidade da detecção. A câmera escolhida foi a FLIR Lepton 2.5, que se conecta ao microcontrolador via uma interface SPI. [19]

O STM32H7 estará conectado via uma interface TFT com uma tela LCD para exibir os parâmetros de funcionamento do sistema como velocidade da esteira e temperatura. A tela escolhida foi o modelo WF121ETWAMLNN0 [7], pois é compatível com o protocolo de comunicação TFT e tem a resolução máxima suportada pelo TFT do microcontrolador (1024x768). Para a conexão com a LCD, é necessário 8 bits de pinos para cada canal de cor (R, G, B) e 3 pinos de clock e sincronização (LCD_CLK, LCD_VSYNC e LCD_HSYNC), diferentes dos usados nas câmeras. 

Embora as conexões com a câmera de luz visível (10 + 3), a câmera infravermelho (3) atuadores (2+2) e LCD (24 + 3) ocupem uma quantidade considerável de pinos, o modelo de packaging possui 169, mais do que o suficiente para todos os sistemas de sensoreamento e atuação. 


#### Controle da Esteira

![image](https://github.com/hsrocha-source/optisort/assets/113446522/1b8594bb-99cb-41f0-8a70-abda2bdf7aa9)

Na imagem apresentada anteriormente, retirada de [14], podemos visualizar o diagrama de blocos correspondente à esteira transportadora que o projeto vai utilizar. O "stream" de entrada será um conjunto de frutas colocados, em grandes números, pelo usuario. Estas frutas passarão, depois, por um fúnil que irá limitar a quantidade que vai entrar na esteira motorizada. O diagrama da esteira está apresentado na imagem abaixo, também retirada de [14].

![DiagramaEstimado](https://github.com/hsrocha-source/optisort/assets/113446522/a6dfcc02-1946-4f32-9df1-2aa4caf2072d)

Ela será adquirida de uma das empresas de produção de esteiras dentro do estado de São Paulo (como sendo [9] e [10]), favorecendo o modelo modular pela simplicidade da limpeza das suas peças. Estima-se a esteira seja de uns 3 m de extensão. O CLP da esteira solicitada precisa ter acesso ao padrão EIA485 (RS485) de comunicação serial, que será utilizado para interconectar o controlador lógico com o STM32H7. Por conta dos níveis de tensão associados ao padrão serial (-7V até +12V) iremos usar um conversor TTL a RS485 montado com o chip MAX485 (visível neste link [11]), seguindo a montagem utilizada em módulos comerciais (como [12]). No projeto deste circuito conectaremos um conjunto de pinos RX e TX do USART do STM32H7 no MAX485, ligando ele no nosso CLP mediante um cabo de Ethernet CAT5, atendendo as especificações de cabo para o EIA422 (padrão anterior) [13]. Mediante esta conexão serão controlados e supervisionados aspectos da esteira, como a velocidade. A correia transportadora precisa ser modular (como aquela apresentada em [9]) para permitir funilamento e espaçamento dos elementos colocados no "stream" de entrada. 

A câmera precisa estar com uma angulação de 45° com relação à esteira, de forma que consiga enxergar os componentes em cima da esteira desde um plano superior. Feito o reconhecimento conforme apresentado na seção anterior, dois dos pinos GPIO do STM32H7 (pinos digitais) serão utilizados para o acionamento de dois cilindros pneumáticos [16], que, por conta da sua velocidade e força de acionamento, vão servir como o nosso atuador separador de fruta estragada. Para disparar os cilindros iremos utilizar duas válvulas pneumáticas 5/2 com solenoide [15], que, devido à tensão de operação (12V), serão acionadas mediante Mosfets FQP30N06L conectados aos pinos digitais escolhidos. Cada válvula estará conectada à fonte de gás pressurizado, cuja pressão depende da velocidade desejada para o cilindro, que pode ser escolhida olhando na tabela em [16]. Finalmente, os cilindros terão uma impressão 3D cobrindo a sua ponta, tal que a área em contato com a fruta seja plana e não pontual, de forma a distribuir melhor a força na superficie da fruta impactada.

Note-se que a montagem requer bastante espaço, com 3m^3 (3x1x1) para ela. A sala precisa contar com acesso à rede elétrica para utilizar uma fonte de alimentação [17], com o objetivo de obter as tensões de alimentação para os circuitos e o acionamento dos dois cilindros. Abaixo da esteira pode-se colocar um cesto grande coletor de fruta estraga, ou pode-se colocar um sistema de funilamento que coloca a fruta estraga numa outra esteira transportadora.

### Especificação de Algoritmos
![Fluxograma do algoritmo de acionamento de atuadores de ar comprimido](./Algo1.pdf)

As imagens serão inseridas na RAM pelo controlador de DMA do microcontrolador STM32H7, o que economiza o tempo do processador principal para executar o modelo de aprendizado de máquina

A câmera irá utilizar 7.5 fps para que haja tempo suficiente para que a inferência do modelo quantizado ocorra. Caso essa velocidade seja muito rápida para permitir a inferência do modelo, ela poderá ser ajustada via parâmetros de comunicação SPI e DCMI com as duas câmeras. Há maneiras de otimizar modelos de IA para que a inferência deles dure menos que 100 ms em um controlador STM32H7, conforme verificada no artigo [8]. Assim, seguindo as otimizações de modelo estabelecidas em [8], é possível que o processo algoritmico descrito seja executado na velocidade especificada. O artigo executou um modelo de detecção de objetos (MCUNet) em um controlador STM32H7 com 466kB de uso de SRAM e 10fps de velocidade. Vamos utilizar a mesma arquitetura, devido às restrições de hardware similares, alterando o modelo para ser executado em um conjunto de dados combinado da câmera termal/infrafermelha e da câmera colorida.

## Referências
[1] United Nations Environment Programme, Food Waste Index Report 2024. Think Eat Save: Tracking Progress to Halve Global Food Waste. [online]. Available: https://wedocs.unep.org/20.500.11822/45230. [Accessed: Mar. 31, 2024]. 

[2] Brancoli P, Makishi F, Lima PG, Rousta K. Compositional Analysis of Street Market Food Waste in Brazil. Sustainability. 2022; 14(12):7014. [online]. Available: https://doi.org/10.3390/su14127014 . [Accessed: Mar. 31, 2024].

[3] Página de venda do microcontrolador STM32H747AII6. https://br.mouser.com/ProductDetail/STMicroelectronics/STM32H747AII6?qs=vLWxofP3U2xKTIBLp63b7g%3D%3D

[4] Datasheet do microcontrolador STM32H747AII6. https://www.st.com/resource/en/datasheet/stm32h747xi.pdf

[5] Raspberry Pi, para comparação de preço. https://www.raspberrypi.com/products/raspberry-pi-4-model-b/

[6] Datasheet da câmera GC2145. https://e2e.ti.com/cfs-file/__key/communityserver-discussions-components-files/968/GC2145-CSP-DataSheet-release-V1.0_5F00_20131201.pdf

[7] Datasheet da tela LCD WF121ETWAMLNN0. https://www.winstar.com.tw/uploads/files/04170fa78caf6e36d3dcec06f7f1042b.pdf

[8] Lin, Ji, et al. "Mcunet: Tiny deep learning on iot devices." Advances in Neural Information Processing Systems 33 (2020): 11711-11722.

[9] STE Equipamentos: Esteiras Transportadoras. Site de compra para a esteira transportadora modular. url:https://www.steequipamentos.com.br/produto/esteira-transportadora-modular/ [Acessado: 23. Maio. 2024]

[10] TEC: Linhas completas para automação. Site de compra para a esteira transportadora palana. url: https://tecdobrasil.com.br/esteira-transportadora-plana/ [Acessado: 23. Maio. 2024]

[11] Datasheet do MAX485. url: https://www.analog.com/media/en/technical-documentation/data-sheets/MAX1487-MAX491.pdf?ADICID=SYND_WW_P682800_PF-spglobal [Acessado: 23. Maio. 2024]

[12] Conversor TTL a RS485 Comercial. url: https://www.eletrogate.com/conversor-de-dados-ttl-para-rs485 [Acessado: 23. Maio. 2024]

[13] Advantech, "Cable Selection for RS-422 & RS-485 Systems". url: https://www.advantech.com/en/resources/white-papers/2fa5d163-b82f-4f3d-b19a-4cd8dac0b9b0 [Acessado: 23. Maio. 2024]

[14] MB Correias Campinas. url: https://www.mbcorreiascampinas.com.br/ [Acessado: 23. Maio. 2024]

[14] Maier, Georg & Gruna, Robin & Längle, Thomas & Beyerer, Jürgen. (2024). A Survey of the State of the Art in Sensor-Based Sorting Technology and Research. IEEE Access. PP. 1-1. 10.1109/ACCESS.2024.3350987. 

[15] Mercado Livre, "Válvula Pneumática Solenoide/mola 5/2v 1/4 Com Conexões 8mm". url: https://produto.mercadolivre.com.br/MLB-3355213923-valvula-pneumatica-solenoidemola-52v-14-com-conexoes-8mm-_JM?attributes=Vm9sdGFnZW0%3D%3AMTJW&quantity=1 [Acessado: 23. Maio. 2024]

[16] LIDA Automação, "CILINDRO MINI ISO DUPLA AÇÃO DIÂMETRO 20 MM COM AMORTECIMENTO". url: https://www.lidaautomacao.com.br/produtos/cilindro-mini-iso-dupla-acao-diametro-20-mm-com-amortecimento1/ [Acessado: 23. Maio. 2024]

[17] Mercado Livre, "Brazil PC BPC-230 Fonte de alimentação para PC 230W prata 115V/230V" url: https://www.mercadolivre.com.br/brazil-pc-bpc-230-fonte-de-alimentaco-para-pc-230w-prata-115v230v/p/MLB15734602 [Acessado: 23. Maio. 2024]

[18] https://www.st.com/resource/en/application_note/an5020-digital-camera-interface-dcmi-on-stm32-mcus-stmicroelectronics.pdf. DCMI interface details

[19] FLIR Lepton 2.5 Engineering Datasheet. https://flir.netx.net/file/asset/13333/original/attachment
