# `Sistema de Controle e Gerenciamento de Acesso`
# `Access Control and Management System`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Introdução ao Projeto de Sistemas Embarcados*, 
oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> |Nome  | RA | Curso|
> |--|--|--|
> | Thiago Masanori Hata | 194345  | Eng. Elétrica|
> | Victoria Helena Alves Navarro  | 236015  | Eng. Elétrica|


## Descrição do Projeto

> Descrição do objetivo principal do projeto, incluindo contexto gerador, motivação.
> > Um sistema de controle de acesso físico tem a função de gerenciar o acesso de pessoas em uma determinada área garantindo a segurança e a gestão eficiente de acesso, utilizando uma combinação de hardware e software especializados. Com o avanço das tecnologias de autenticação digital, os sistemas de controle de acesso físico ganham muita flexibilidade para implementar métodos mais seguros e práticos para garantir a segurança de usuários. Os métodos mais implementados atualmente incluem a sensores biométricos, senhas ou cartões de identificação RFID(sigla para “Radio Frequency Identification”, significa “identificação por radiofrequência”).
> >

> Escreva essa seção imaginando que está tentando convencer alguém a investir financeiramente no seu projeto.
> > A implementação de um sistema de controle de acesso físico melhora a segurança e eficiência de entrada em edifícios comerciais, residenciais, hospitalares e instituições educacionais.
> > A demanda por controle de acesso seguro está em ascensão, e empresas e organizações buscam soluções confiáveis para garantir quem entra e sai de suas instalações. Nosso sistema oferece uma experiência de acesso mais rápida e conveniente, permitindo que os usuários utilizem biometria facial e QR Code, eliminando a necessidade de chaves físicas. Além disso, a automação do controle de acesso reduz os custos relacionados a gestão de chaves, perdas de chaves e substituição de fechaduras. O mercado de controle de acessos está projetado para crescer significativamente nos próximos anos, tornando esse investimento uma oportunidade com grande potencial.

> > 
> Qual problema vocês pretendem solucionar?
> > Com a nossa ferramenta de controle de acessos pretendemos solucionar problemas relacionados a:
> > - Segurança: a biometria facial é extramamente difícil de ser enganada e o QR code mutável a cada 5 segundos permite um aumento significativo da segurança de acesso
> > - Conveniência: o uso de biometria facial e QR code não exige que o usuário carregue algo além de seu celular para realizar a entrada de forma prática e segura
> > 
> Quem são os potenciais usuários?
> > Empresas, pessoas físicas, comércios e hospitais

> É possível estabelecer um valor econômico associado?
> > Sim, esses sistemas já existentes no mercado são vendidos entre R$2.500,00 e R$4.000,00 a unidade com catraca.


## Descrição Funcional
> A descrição funcional do projeto é a principal entrega do E1 e pode ser realizada neste próprio arquivo Markdown,
> com links para diagramas ou outros arquivos que estejam no próprio repositório.
>  
> 

### Funcionalidades
> Tarefas que o sistema será capaz de executar:
> - O sistema deve ser capaz de se comunicar remotamente (bluetooth, wifi,...)
> - Deve ter acesso à internet
> - Deve ser capaz de captar e transmitir imagens de vídeo (câmera)
> - Deve ser capaz de controlar uma fechadura elétrica ou portão
> - Deve ser capaz de emitir algum sinal que indique que o acesso foi autorizado com sucesso
> - Base de dados (pessoas autorizadas e histórico de acessos)
> > 

### Configurabilidade
> Detalhe, se houver, todas as possíveis configurações do circuito e todos os pontos de alteração da configuração.
>
> A empresa poderá escolher se os usuários utilizarão identificação por biometria facial ou QR via aplicativo.
> - Biometria facial: será necessário que o usuário final envie para a empresa uma foto recente com fundo branco, boa iluminação e sem acessórios como óculos e chapeu. A imagem será armazenada no banco de dados e será utilizar como meio de comparação a cada tentativa de acesso
> - QR Code: o usuário final deverá baixar um aplicativo que será conectado com os dados relacionados a empresa. Após as configurações iniciais, a cada tentativa de login o usuário deverá abrir o aplicativo e apontar o QR Code para a câmera na entrada onde será comparado. O QR code será gerado automaticamente a cada 5 segundos.
>   
### Eventos
> Quais eventos o sistema deve tratar?
> Se aplicável, classifique os eventos que são periódicos (procure especificar a periodicidade) e os que são não-periódicos
> (qual o tempo mínimo entre dois eventos sucessivos)?
> > O sistema deve ser capaz de permanecer em estado de stand by, pois assim que um movimento for dectado ele deve ser capaz de ler o que for apontado para a sua câmera. Sendo um rosto ou um QR code, o sistema deve capturar a imagem e comparar com o banco de dados em um tempo ágil, não mais do que 30 segundos.


### Tratamento de Eventos
> Qual comportamento o sistema deve ter para tratar corretamente cada evento?
>
> O sistema terá comportamentos diferentes para o caso da identificação ou não da imagem recebida frente a base de dados
> - Acesso permitido: se os dados apresentados pelas formas de identificação forem iguais as cópias de segurança, o acesso será liberado e a mensagem "Acesso Permitido" aparecerá na tela.
> - Acesso negado: se os dados apresentados pelas formas de identificação forem diferentes das cópias de segurança, o acesso será negado e a mensagem "Acesso Negado. Favor procurar a administração" aparecerá na tela.

## Descrição Estrutural do Sistema
> Junto com a descrição do comportamento do sistema, deve-se especificar, em nível de bloco ou sistema, a estrutura necessária 
> para captar os eventos do mundo externo, para alojar e processar o programa de tratamento de eventos, e para atuar sobre o mundo externo.
>
> Para essa descrição recomenda-se a criação de diagramas de blocos.
> Nesse diagrama, devem ser destacados os blocos funcionais que compõem o sistema, incluindo uma síntese das funcionalidades de cada bloco.
> Além disso, deve-se esclarecer também o relacionamento entre estes blocos, incluindo os principais sinais de comunicação entre
> os blocos de forma a assegurar a execução de todas as tarefas que o sistema deve realizar.

> ![Alt](images/Diagrama_acesso.drawio.svg)
>
> 1. O módulo de entrada com reconhecimento facial ou QR Code é responsável por capturar as imagens e processá-las para identificação
> 2. O banco de dados armazena as informações sobre os usuários com ID, foto e permissões de entrada. Utilizado para relacionar os resultados o módulo de entrada com cada usuário
> 3. O controlador de acesso recebe os dados dos módulos 1 e 2 e toma as decisões de liberar ou não o acesso
> 4. A catraca/porta são os pontos físicos controlados pelo módulo 3
> 5. A interface com o usuário é um aplicativo móvel ou painel de controle no qual ele pode sozinho ou com auxilio de um administrador inserir as suas informações e solicitar acessos.
> 
Você sabia? Ferramentas como o `draw.io` permitem integração com o Github.
>  

## Referências
> Seção obrigatória. Inclua aqui referências utilizadas no projeto.
> 1) Controle de acesso à rede: saiba tudo sobre essas soluções ... - Varonis. https://www.varonis.com/pt-br/blog/controle-de-acesso-a-rede-saiba-tudo-sobre-essas-solucoes-e-sua-importancia.
> 2) Kit RFID com Arduino: Sistema de Controle de Acesso. https://blog.eletrogate.com/kit-rfid-com-arduino-sistema-de-controle-de-acesso/.
> 3) Controle de Acesso com RFID e Arduino - Lobo da Robótica. https://lobodarobotica.com/blog/controle-de-acesso-arduino-rfid/.
> 4) 5 sistemas grátis e open source de monitoramento de rede. https://www.capterra.com.br/blog/1583/monitoramento-de-rede.
> 5) 5 programas de acesso remoto para controlar o seu PC a distância. https://www.techtudo.com.br/listas/2023/07/quer-controlar-seu-pc-a-distancia-veja-5-programas-de-acesso-remoto-edsoftwares.ghtml.
> 6) Acesso remoto: veja o que é e como fazer em outro PC ou celular via app. https://www.techtudo.com.br/noticias/2023/02/o-que-e-acesso-remoto-entenda-tudo-sobre-conexao-distancia-edsoftwares.ghtml.
> 7) Sistema de Controle e Gerenciamento de Acesso. https://riu.ufam.edu.br/bitstream/prefix/6638/11/TCC_DavidFigueira.pdf.
