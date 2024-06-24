# `Painéis Solares de Inclinação Adaptável`
# `Adaptive Tilt Solar Panels`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Introdução ao Projeto de Sistemas Embarcados*, 
oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

|Nome  | RA | Curso|
|--|--|--|
| Mateus Alves Silva | 239856 | Eng. Elétrica |
| Nathália Kaori Gondo | 239903 | Eng. Elétrica |


## Arquivos Importantes

Esquemático em PDF: (link para imagens/pdf esquemático)
Lista de Componentes: https://github.com/nathaliagondo/ea075-2024.1/blob/main/projetos/painel-solar/componentes.md
PCB: link para imagens/pdf PCB


## Descrição do Projeto
Com o crescente interesse por fontes de energia limpas e renováveis, a energia solar se destaca como uma opção viável tanto para residências quanto para indústrias. No entanto, a eficiência dos painéis solares fixos é limitada pela sua incapacidade de ajustar a inclinação em resposta às variações na incidência solar ao longo do dia. O projeto "Painéis Solares de Inclinação Adaptável" visa resolver este problema desenvolvendo um sistema embarcado capaz de automatizar o ajuste da inclinação dos painéis solares, garantindo uma captação ótima de energia durante todas as horas do dia.

O objetivo principal do projeto é criar um sistema inteligente que ajuste automaticamente a inclinação dos painéis solares para maximizar a captação de energia solar. Esse sistema acompanhará o movimento do sol, mantendo os painéis sempre perpendiculares aos raios solares, resultando em uma eficiência significativamente maior na geração de energia.

Motivado pela necessidade crescente de fontes de energia sustentáveis e pela evolução das tecnologias de geração de energia, este projeto foi desenvolvido no contexto da disciplina de graduação EA075 - Introdução ao Projeto de Sistemas Embarcados. Busca-se contribuir significativamente para a tecnologia de energia renovável, tornando-a mais acessível e eficiente.

Os painéis solares fixos enfrentam a limitação de não se ajustarem às mudanças na posição do sol ao longo do dia, o que reduz sua eficiência na captação de energia solar. O sistema de inclinação adaptável resolve esse problema ao ajustar dinamicamente a posição dos painéis solares, garantindo que eles estejam sempre na posição ideal para captar a máxima quantidade de energia.

Os potenciais usuários deste sistema incluem proprietários de residências que desejam reduzir suas contas de energia e aumentar a eficiência de seus sistemas solares, indústrias e empresas que buscam soluções sustentáveis e eficientes para reduzir custos operacionais, governos e instituições públicas que investem em infraestrutura de energia renovável para alcançar metas de sustentabilidade, e fazendas solares que visam maximizar a produção de energia solar em larga escala.

Investir no sistema de inclinação adaptável oferece benefícios econômicos significativos. Pesquisas e estudos na literatura técnica indicam que a capacidade dos painéis solares de seguirem o sol ao longo do dia pode aumentar a produção de energia em até 30% em comparação aos sistemas fixos. Estudos como o realizado pela RatedPower mostram que otimizar a inclinação dos painéis solares para acompanhar a posição do sol pode melhorar substancialmente a geração de energia ao longo do dia e do ano, enquanto outras pesquisas indicam que a utilização de sistemas de rastreamento solar pode resultar em aumentos de eficiência de até 30% em determinadas condições​ [RatedPower — Smart flow for energy]​. Essa eficiência aprimorada leva a uma maior rentabilidade dos investimentos em energia solar, reduzindo os custos com energia elétrica. Com a maior produção de energia, o tempo de retorno do investimento em painéis solares é reduzido, tornando a tecnologia mais atrativa financeiramente. Além disso, projetos que promovem o uso de energias renováveis são frequentemente elegíveis para incentivos governamentais e subsídios, aumentando ainda mais o valor econômico do investimento.

Em resumo, o projeto "Painéis Solares de Inclinação Adaptável" não apenas promove o avanço da tecnologia de energia renovável, mas também oferece uma solução econômica e eficiente para maximizar a captação de energia solar. Com um sistema inteligente de ajuste de inclinação, é possível garantir uma produção de energia otimizada, tornando os investimentos em energia solar mais rentáveis e sustentáveis.


## Descrição Funcional
O sistema de foi concebido para operar em tempo real, monitorando a intensidade da luz solar incidente sobre o painel solar e ajustando sua inclinação para maximizar a geração de energia. Durante o desenvolvimento, várias melhorias foram implementadas para otimizar o funcionamento do sistema e resolver problemas identificados durante os testes.

O sistema utiliza sensores especializados para detectar a intensidade e a direção da luz solar. Esses sensores fornecem dados que são processados por um microcontrolador, responsável por calcular o ângulo ideal de inclinação dos painéis solares. Em seguida, um algoritmo de controle ajusta a inclinação em tempo real, garantindo que os painéis estejam sempre na posição mais vantajosa para captar a máxima quantidade de energia solar.

Durante o desenvolvimento do projeto, algumas dificuldades foram encontradas, exigindo ajustes e melhorias. Inicialmente, a precisão dos sensores de luminosidade não era suficiente para garantir ajustes precisos da inclinação dos painéis. Além disso, o algoritmo de controle enfrentou dificuldades em condições de luz variável, resultando em ajustes menos eficientes. Por fim, os testes revelaram que a estrutura dos painéis precisava ser reforçada para resistir a condições de vento forte sem comprometer a operação.

Para resolver esses problemas, foram implementadas as seguintes melhorias: os sensores de luminosidade foram substituídos por modelos mais precisos, especificamente o VEML6075, que fornecem dados mais confiáveis sobre a intensidade da luz UV. O algoritmo de controle foi reformulado para incluir uma lógica mais sofisticada, utilizando técnicas de machine learning para prever a posição ideal dos painéis com base em dados históricos e em tempo real. Além disso, a estrutura dos painéis foi reforçada para aumentar a resistência ao vento, garantindo estabilidade e segurança em condições climáticas adversas.

Atualmente, o sistema opera monitorando continuamente a intensidade da luz solar utilizando sensores VEML6075. Os dados coletados são processados pelo microcontrolador ESP32, que calcula o ângulo de inclinação ideal. Em seguida, um servo motor ajusta a inclinação dos painéis solares em tempo real. O sistema inclui também uma interface de usuário acessível via aplicativo, permitindo monitoramento remoto e ajustes manuais, se necessário. Para garantir operação contínua mesmo em condições de baixa luminosidade, o sistema é alimentado pela energia solar gerada, com uma bateria de backup.

O sistema oferece vários benefícios econômicos e operacionais. Ao maximizar a captação de energia solar, ele melhora significativamente a eficiência dos painéis solares, reduzindo custos operacionais e aumentando a rentabilidade dos investimentos em energia solar. Com a implementação de um algoritmo de controle mais eficiente e sensores de alta precisão, o sistema opera de forma robusta e confiável, contribuindo para a sustentabilidade e a viabilidade econômica das instalações de energia solar.

Em resumo, o projeto "Painéis Solares de Inclinação Adaptável" evoluiu significativamente desde sua ideia inicial, com melhorias substanciais na precisão, eficiência e robustez do sistema. Essas melhorias foram implementadas para garantir que o sistema ofereça um desempenho ótimo e confiável em todas as condições de operação.

![image](https://github.com/nathaliagondo/ea075-2024.1/assets/165518289/a88782cf-e8c2-4046-9547-955450b393e3)

Figura 1. Representação do sistema embarcado - Painéis solares de inclinação adaptável.

### Funcionalidades
1. _Sun tracking_: o sistema irá monitorar a posição solar usando sensores e ajustando o ângulo de inclinação dos painéis solares para garantir a maior exposição aos raios incidentes.
2. Controle da angulação dos painéis solares.
3. Verificação de luminosidade: verifica se a luminosidade está acima de um _threshold_ para permitir a operação.
4. Suspensção do sistema em caso de luminosidade baixa.
5. Interface com o usuário: uma interface que permita o usuário configurar, ajustar o sistema além de apresentar os dados de produção de energia além de informações operacionais do dispositivo.
6. Maximização da energia produzida: algoritmo de controle que garanta a máxima geração energética com base na adaptação da angulação do painel solar. Os dados serão processados por meio da tensão e corrente recebidas pelos painéis.
7. Comunicação _wireless_: o sistema deverá possuir comunicação sem fio para enviar informações dos sensores e receber dados de controle e configuração de um aplicativo para smartphone.
8. Gerenciamento de energia: o sistema será alimentado com a energia solar gerada pelo próprio painel que alimentará uma bateria (usada como _backup_). A bateria funcionará como um suporte para estabilização da tensão fornecida ao dispositivo. O gerenciamento de energia é essencial para otimizar o consumo de energia e prolongar o tempo de funcionamento do dispositivo.
9. Identificação de erro no sistema ou condição extrema: verificar esforço extra que o motor é submetido ou falha de energia.
10. Retornar a uma posição segura em caso de algum erro ou para manutenção.
11. Sistema de bateria como _backup_ de energia com recarga automática.


### Configurabilidade
1. Faixa de ângulo de varredura: define os valores máximos e mínimos do ângulo que os painéis podem ser inclinados.
2. Frequência do ajuste da posição: define de quanto em quanto tempo o sistema irá realizar os ajustes de inclinação.
3. Limite mínimo de luminosidade para o sistema operar  para evitar desperdício de energia.
4. Posição inicial que o sistema irá começar processo de varredura
5. Posição segura para caso erro no sistema ou condição climática extrema ou para manutenção.
6. Velocidade da mudança da inclinação dos painéis.
7. Tempo de funcionamento máximo.


### Eventos
- Eventos periódicos:
1. Período útil de geração de energia (diário, a cada 24 horas): o período do dia durante o qual o sistema está ativo para captar energia solar e gerar eletricidade. Começando ao nascer do sol e terminando ao pôr do sol, é o intervalo em que a intensidade da luz solar é suficientemente alta para uma produção eficaz de energia.
2. Mudança da posição do sol (diário, a cada poucos minutos - constante): ao longo do dia, a posição do sol no céu se desloca gradualmente devido à rotação da Terra. Essa mudança afeta a quantidade de luz solar que atinge os painéis solares. O sistema deve ajustar a inclinação dos painéis para maximizar a absorção de energia solar, geralmente mantendo-o perpendicular aos raios incidentes.
3. Mudança nas estações do ano (sazonal, a cada três meses, com mudanças graduais entre uma estação e outra): as estações do ano afetam a intensidade e a duração da luz solar incidente devido à inclinação do eixo da Terra. O sistema deve ajustar sua operação e estratégias de captação de energia para otimizar o aproveitamento da luz solar em cada estação.
- Eventos não-periódicos:
4. Condições adversas (variável, depende da frequência e duração das condições): momentos em que as condições climáticas, como nebulosidade, reduzem a intensidade da luz solar disponível para captação. Isso pode resultar em uma diminuição temporária na produção de energia.
5. Condições extremas (variável, depende da frequência e gravidade das condições): eventos climáticos severos, como tempestades e ventanias, que representam riscos para às placas solares. Nessas situações, medidas de segurança devem ser ativadas para proteger os componentes, levando-o à posição referencial.
6. Manutenção das placas solares ou dos componentes do sistema (variável, depende do cronograma de manutenção de cada componente): eventos planejados para garantir o bom funcionamento e a longevidade do sistema. Isso inclui inspeções regulares, limpeza de painéis solares para melhor obtenção dos dados e substituição de peças desgastadas.
7. Bateria fraca (variável, condicionada pelo padrão de consumo do sistema): indica que a carga da bateria de armazenamento de energia atingiu um nível baixo. Isso pode ocorrer devido a um consumo excessivo de energia ou a uma incapacidade de recarga adequada das placas solares.
8. Interação do usuário (variável de acordo com a necessidade do usuário): dedicado quando o usuário interage com o sistema, como ajustar configurações, monitorar o desempenho ou receber notificações sobre o status do sistema.
9. Falhas no sistema (imprevisível, dependendo da natureza e gravidade da falha): ocorrência de problemas ou mau funcionamento no sistema solar que exigem intervenção técnica. Isso pode incluir falhas de hardware, erros de software ou interrupções na geração de energia.


### Tratamento de Eventos
1. Período útil de geração de energia: 
    - Iniciar automaticamente os painéis solares e o sistema de geração de energia ao nascer do sol e ajustar a inclinação dos painéis solares ao longo do dia para acompanhar o movimento do sol, de modo a maximizar a captação de energia.
    - Desativar o sistema de busca pelo ângulo ótimo no pôr do sol e monitoramente da produção de energia para evitar a consumo de energia desnecessária durante a noite.
2. Mudança da posição do sol:
    - Ajustar a inclinação dos painéis solares em tempo real para garantir que estejam sempre alinhados da maneira mais eficiente possível com a incidência de luz solar.
    - Monitorar continuamente a produção de energia e consumo, realizando ajustes automáticos na inclinação ao longo do dia para acompanhar o movimento do sol e otimizar a eficiência energética.
3. Mudança nas estações do ano:
    - Com base na data e posição do sol, ajustar as configurações de inclinação dos painéis solares e os algoritmos de captação de energia para otimizar o desempenho de acordo com as condições específicas de cada estação.
    - Adaptar as estratégias de armazenamento e uso de energia para melhor atender às necessidades sazonais de energia.
4. Condições adversas:
    - Monitorar a ocorrência de mudanças na obtenção dos dados, para ajusar as operações dos painéis solares, lidando com a redução na intensidade da luz solar.
    - Implementar medidas de economia de energia para preservar a energia disponível durante períodos de baixa produção.
5. Condições extremas:
    - Identificar ventanias e tempestades por meio de variações bruscas no torque do servomotor. 
    - Ativar um modo de segurança que retraia os painéis solares e desative temporariamente a geração de energia para proteger os componentes do sistema contra danos.
    - Emitir alertas aos usuários sobre as condições climáticas extremas.
6. Manutenção das placas solares ou dos componentes do sistema:
    - Agendar automaticamente tarefas de manutenção com base em intervalos predefinidos ou em condições específicas do sistema.
    - Desativar temporariamente os painéis solares e o sistema durante a manutenção para garantir a segurança durante as limpezas e as substituições de componentes desgastados.
7. Bateria fraca:
    - Monitorar continuamente o nível de carga da bateria de armazenamento de energia.
    - Reduzir automaticamente o consumo de energia ou ajustar as operações dos painéis solares para preservar a energia restante da bateria.
    - Emitir alertas aos usuários sobre a bateria fraca.
8. Interação do usuário:
    - Prioridade em relação aos demais eventos, respondendo rapidamente às solicitações.
    - Interface intuitiva sistema-usuário
9. Falhas no sistema:
    - Tentar realizar correções automáticas, quando possível, e diagnósticos das falhas.
    - Se não for possível corrigi-lo, desativar o sistema e emitir alertas ao usuário indicando as falhas.


## Descrição Estrutural do Sistema
O sistema possuirá um painel ou grupo de painéis solares ligados a um eixo de rotação conectado a um servo motor industrial responsável por permitir a dinâmica do sistema. Além disso, deve possuir sensores fotossensíveis para interpretar a luminosidade e a luz incidente nos painéis, possuir um microcontrolador com comunicação sem fio para que consiga enviar e receber dados de um usuário além de interpretar o algoritmo de controle do sistema. Precisa-se de uma bateria que garanta que o sistema funcione mesmo com quedas de energia.

Em primeiro lugar haverá a inicialização do sistema onde os componentes de sensoriamento (sensores fotosenssíveis) e do servo motor irão ser ligados e calibrados, assim como os componentes de comunicação. Logo após, o sistema irá realizar uma checagem dos componentes verificando algum erro ou condições extremas de clima. Caso haja algum problema, o sistema irá se manter em uma posição segura definida pelo usuário, além de comunicá-lo via comunicação _wireless_. O sistema deve checar também se sua fonte de alimentação é sua bateria interna de _backup_. Caso afirmativo, ele também deve comunicar ao usuário a falta de energia.

Se a checagem do erro passar sem problemas, o servo motor deve ajustar o eixo a uma posição inicial de operação também pré-definida pelo usuário, e verificar se há a necessidade de recarregar a bateria de _backup_. Caso seja preciso, faz-se a carga da mesma. Após a máquina na posição correta, o sistema verifica a luminosidade do dia por meio dos fotossensores e de dados recebidos do inversor do painel solar e, caso essa luminosidade não ultrapasse o valor mínimo, o sistema é suspendido automaticamente. Caso contrário, ele inicia o processo de ajuste de máxima geração de energia, ajustando a posição dos painéis pelo servo motor, checa a incidência solar e novamente pelos sensores e pela energia produzida, se necessário, se ajusta novamente até encontrar a posição ideal. Quando encontrada essa posição, permanecerá nela por um tempo definido pelo usuário. Após esse tempo, o sistema volta a verificar a luminosidade e repete o processo de ajuste de posição. 

Observa-se que o usuário pode interromper a rotina do sistema por seus comandos, podendo inicializar o sistema manualmente, desligar o sistema, suspendê-lo e ainda manter posição de segurança. Após certo tempo, também definido pelo usuário, o sistema se inicializa automaticamente para que ele opere sem a necessidade do usuário ligá-lo sempre no dia-a-dia.

O diagrama das atividades podem ser vistas pela Figura 2. abaixo.

![Inicializar](https://github.com/nathaliagondo/ea075-2024.1/assets/165518289/fc771e96-53b4-4542-a22a-ef8bc89a5591)

Figura 2. Diagrama de blocos dos processos realizados pelo sistema.


## Especificações (⚠️ NOVO ⚠️)

### Especificação Estrutural
Para facilitar o entendimento, o projeto foi dividido em cinco grandes partes, que serão detalhadas ao longo da descrição estrutural e podem ser visualizadas na Figura 3. O diagrama apresentado ilustra o funcionamento de um sistema de controle de angulação de painéis solares, utilizando um microcontrolador alimentado por um painel solar com backup de bateria e regulador de tensão.

![especificação](https://github.com/nathaliagondo/ea075-2024.1/assets/165518028/a15c2f9f-70f6-43b7-8b9a-68c649dca67d)
Figura 3. Diagrama estrutural do sistema.

Em resumo, o painel solar fornece energia ao sistema e carrega a bateria de backup, enquanto o regulador de tensão garante uma alimentação estável. O sensor de radiação mede a intensidade da radiação UV e envia os dados ao microcontrolador. Este, por sua vez, calcula a inclinação ideal dos painéis solares e envia comandos ao driver do servomotor para ajustar a posição dos painéis. A antena externa permite a comunicação com o usuário para monitoramento e ajustes remotos.
Este sistema integrado assegura que os painéis solares estejam sempre na melhor posição para capturar a máxima quantidade de energia solar, otimizando a eficiência e o desempenho geral do sistema.

#### Alimentação do microcontrolador
Para que o microcontrolador funcione de maneira autônoma, sem depender da rede elétrica, sua alimentação será feita por meio de um painel solar. O painel solar capta a energia solar e a converte em energia elétrica, que é utilizada para alimentar o sistema e carregar uma bateria de backup. Devido à instabilidade na tensão de saída dos painéis solares, é necessário um regulador de tensão entre o painel solar e a bateria de backup. Esta bateria armazena energia para garantir que o sistema continue funcionando mesmo quando a intensidade da luz solar é baixa ou durante períodos sem incidência solar, como à noite. Um segundo regulador de tensão recebe a energia da bateria e a converte para uma tensão estável adequada para alimentar o microcontrolador e outros componentes eletrônicos, garantindo uma alimentação constante e confiável.

O painel solar considerado para a análise é da marca Risen Energy, amplamente utilizado em projetos residenciais, comerciais e industriais. Ele possui uma massa em torno de 25 kg e dimensões de 2108 x 1048 x 35 mm, com uma potência fornecida de 445W. A tensão de circuito aberto do painel é aproximadamente 50V e, em potência máxima, a tensão é reduzida para 41,7V. Portanto, é necessário um regulador de tensão que suporte essa tensão de entrada. No projeto, será utilizado o regulador LM2576, que suporta uma tensão de entrada de até 60Vdc e fornece uma saída de até 26Vdc, ajustada para 12V, a mesma tensão da bateria. Também será necessário um segundo regulador para converter a tensão de 12V para os 3,3V necessários para alimentar o microcontrolador. O LM2576 cumpre os requisitos para ambos os casos.

A bateria, por sua vez, deve ser capaz de alimentar o microcontrolador por no mínimo 12 horas, uma vez que este é o tempo mínimo em que os painéis solares não estarão gerando energia. Entretanto, para considerar períodos desfavoráveis para a captação de energia solar, será utilizada uma bateria mais robusta. A bateria estacionária utilizada terá uma capacidade de 36 Ah a 12V. Considerando um consumo máximo do ESP32 de 500mA, com uma margem de segurança, seria possível manter o sistema ligado por no mínimo 72 horas, ou 3 dias completos, considerando um consumo máximo, o que raramente ocorrerá.

Esta configuração de alimentação, utilizando reguladores de tensão e uma bateria robusta, garante que o microcontrolador ESP32 e o sistema de controle de angulação dos painéis solares operem de forma eficiente e confiável, mesmo durante períodos de baixa incidência solar ou à noite.

#### Sensor para controle na angulação dos painéis solares, unidade processadora (microcontrolador) e comunicação com o usuário
Uma vez que a tensão fornecida pelo painel solar pode ser a mesma sob diferentes condições de radiação solar, conforme ilustrado na Figura 4, torna-se impraticável usar a saída do painel para verificar continuamente a variação de tensão gerada. A solução mais precisa é utilizar um sensor fotossensível. O sensor de radiação VEML6075 mede a intensidade da radiação UVA e UVB e envia esses dados ao microcontrolador por meio da interface I2C (Inter-Integrated Circuit). A I2C, sendo um barramento de comunicação serial, permite a conexão de múltiplos dispositivos usando apenas dois fios: um para o clock (SCL) e outro para os dados (SDA). Com base nas leituras dos sensores, o microcontrolador calcula a inclinação ideal dos painéis solares para maximizar a eficiência energética.

![painel-solar](https://github.com/nathaliagondo/ea075-2024.1/assets/165518028/85aaaa85-a13c-40c3-9885-7840aa0c8611)
Figura 4. Valores de saída de corrente e potência da placa solar dadas condições de tensão de saída.

O microcontrolador utilizado no projeto é o ESP32-S3-WROOM-1, devido às suas capacidades avançadas de comunicação, processamento e eficiência energética. A interface I2C facilita a integração com sensores de radiação UV, e uma ampla gama de periféricos, como GPIOs, SPI, UART, ADC e PWM, permite conectar e controlar diversos componentes do sistema, possibilitando maior integração e expansão conforme necessário.

O ESP32-S3-WROOM-1 possui um processador dual-core de 32 bits, operando a até 240 MHz, essencial para realizar tarefas em tempo real, como leitura de sensores, processamento de dados e controle de atuadores. Isso garante que o sistema responda rapidamente às mudanças nas condições ambientais, ajustando a inclinação dos painéis solares conforme necessário para otimizar a captação de energia. Com até 16 MB de Flash e 8 MB de PSRAM, o ESP32 oferece ampla capacidade de memória, suficiente para gerenciar grandes volumes de dados de sensores e executar programas complexos de controle e monitoramento.

Além disso, o suporte integrado para Wi-Fi e Bluetooth 5 permite uma comunicação sem fio eficiente e estável. A conectividade Wi-Fi é crucial para o monitoramento remoto do sistema, permitindo que dados como a posição dos painéis solares, a intensidade da radiação solar e o estado da bateria sejam enviados para uma interface de usuário remota. O Bluetooth LE oferece opções adicionais de conectividade para configuração e manutenção locais. A variante ESP32-S3-WROOM-1U, que inclui um conector para antena externa, melhora significativamente a recepção e transmissão de sinais Wi-Fi, garantindo uma comunicação estável em ambientes desafiadores.

#### Atuador de controle da angulação dos painéis solares
Para o atuador de controle da angulação dos painéis solares, o sistema utiliza um motor de passo junto com um driver de controle. O driver do motor recebe comandos do microcontrolador ESP32 e controla o motor de passo com base nesses comandos, ajustando a inclinação dos painéis solares conforme necessário. O motor de passo atua como o elemento físico que realiza o ajuste da inclinação dos painéis solares, movendo-os conforme os sinais recebidos do driver, que, por sua vez, são baseados nos cálculos do microcontrolador a partir dos dados dos sensores de radiação.

![motor](https://github.com/nathaliagondo/ea075-2024.1/assets/165518028/136879f8-1e85-441e-99c1-7029adbbec70)
Figura 5. Lógica de funcionamento dos pinos de controle do servomotor.

O motor de passo utilizado é do tipo EasyServo, que possui um encoder acoplado, permitindo obter automaticamente a posição do seu eixo com alta precisão. A conexão de controle e alimentação do motor é feita através do driver, enquanto as conexões de controle do driver são feitas no microcontrolador ESP32. A tabela da Figura 5 ilustra as posições possíveis do eixo do motor. Para garantir a comunicação correta entre o driver e o microcontrolador, é necessário um circuito amplificador de tensão, uma vez que os sinais do ESP32 são de 3.3V e o driver requer sinais de pelo menos 5V. Para esse circuito será utilizado o Transistor bipolar de junção PNP 2N54N01.

O torque necessário para sustentar e mover a placa solar, considerando suas especificações, é de aproximadamente 128Nm. No entanto, o motor EasyServo fornece um torque de apenas 12Nm. Para que esse motor possa ser utilizado de forma eficaz, é necessário acoplar um redutor de torque. A solução ideal é utilizar um redutor com uma relação de 1:15, aumentando o torque fornecido pelo motor para 180Nm, o que garante uma margem de segurança adequada.

Além disso, a tensão de alimentação do driver varia entre 30V e 110Vdc ou 20V e 80Vac, sendo utilizada a tensão da rede para a alimentação do dispositivo por meio de uma fonte chaveada de 500W suficiente para alimentação do Driver e do motor de passo. Isso facilita a integração do sistema em diversos ambientes e garante uma alimentação constante e confiável para o motor e o driver.


### Especificação de Algoritmos 
- Período útil de geração de energia
	1. Identifica se a mínima claridade foi atingida por tempo mínimo
 	2. Inicializa sistema de inclinação variável;
	3. Conferência de segurança se há erro ou condição extrema;
	4. Sem problemas: Posiciona placa para posição inicial;
	5. Rotina de funcionamento;
	6. Identifica que a mínima claridade não é mais satisfeita por tempo mínimo;
	7. Suspensão do Sistema.

- Mudança da posição do Sol (Sistema já inicializado pelo algoritmo anterior)
	- Loop
	1.  Verifica que a claridade atual é menor que a claridade anterior;
	2. Se maior ou igual: Mantém posição;
	3. Se menor: Ajuste de posição;
	4. Após tempo definido retorna para 1.

- Estações do ano
	1. Verifica dia e mês do ano;
	2. Ajusta parâmetros de funcionamento para cada estação.

- Condições adversas
	1. Identifica que luminosidade é baixa por tempo mínimo;
	2. Se luminosidade muito baixa: Suspende sistema;
	3. Funcionamento normal caso contrário.

- Condições extremas
	1. Sinal do driver de esforço excessivo do motor ou sensores sem resposta;
	2. Mantém painel em posição segura pré-definida;
	3. Comunicar ao usuário.

- Manutenção das placas ou do sistema
	1. Comando do usuário para posição pré-definida de manutenção;
	2. Mantém painel em posição pré-definida;

- Bateria fraca (bateria fica sempre carregada a menos que haja falta de energia)
	1. Verifica tensão na bateria;
	2. Se tensão baixa por tempo definido: Comunicar usuário;

- Interação com usuário (Dois possíveis triggers)
  	- Situação 1:
	1. Comando do usuário para ajuste dos parâmetros;
	2. Atribui novos valores para os parâmetros.
 	- Situação 2:
	1. Comando do usuário de controle manual;
	2. Ajuste da posição do painel para a definida pelo usuário.
	
- Falhas no sistema
	1. Identificação de erros do microcontrolador;
	2. Mantém painel em posição segura pré-definida;
	3. Comunicar ao usuário.


## Referências

https://ratedpower.com/blog/pv-panel-tilt/

[1] Silva, Marcelo Allan de Melo. Projeto de suporte com inclinação variável para placas solares residenciais. 2023. 70 f. Trabalho de Conclusão de Curso (Graduação em Engenharia Mecânica) - Departamento de Engenharia Mecânica, Centro de Tecnologia e Geociências, Universidade Federal de Pernambuco, Recife, 2023. Disponível em: https://repositorio.ufpe.br/handle/123456789/50687. Acesso em: 30 de março de 2024.

[2] Ferronato, Régis; Severo, Tiago Cassol. Análise do Rendimento de um Módulo Fotovoltaico com Suporte de Inclinação Variável. In: Congresso Internacional de Tecnologias para o Meio Ambiente, 6., Bento Gonçalves, RS, Brasil, 10-12 de abril de 2018. Bento Gonçalves: UCS, 2018. Disponível em: https://siambiental.ucs.br/congresso/getArtigo.php?id=490&ano=_sexto. Acesso em: 30 de março de 2024.

[3] Cravo, E. (s.d.). Servo Motor: o que é um, como funciona e quais as vantagens? Recuperado de: https://blog.kalatec.com.br/o-que-e-servo-motor/?utm_source=google&utm_medium=cpc&utm_campaign=npbr_search_DSA&utm_id=21012797249&utm_term=&gad_source=1&gclid=CjwKCAjwtqmwBhBVEiwAL-WAYQnYY9Xp7LGsU-SsAqGSzuhZBELNIFGqw1FDFUnbnq8aRlu-L0fVyBoC-r4QAvD_BwE
