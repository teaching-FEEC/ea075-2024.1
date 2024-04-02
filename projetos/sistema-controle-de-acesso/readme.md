# `Sistema de Controle e Gerenciamento de Acesso`
# `Access Control and Management System`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Introdução ao Projeto de Sistemas Embarcados*, 
oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> |Nome  | RA | Curso|
> |--|--|--|
> | Thiago Masanori Hata | 194345  | Eng. Elétrica|
> | Nome2  | 123456  | Eng. de Computação|


## Descrição do Projeto

> Descrição do objetivo principal do projeto, incluindo contexto gerador, motivação.
> > Um sistema de controle de acesso físico tem a função de gerenciar o acesso de pessoas em uma determinada área garantindo a segurança e a gestão eficiente de acesso, utilizando uma combinação de hardware e software especializados. Com o avanço das tecnologias de autenticação digital, os sistemas de controle de acesso físico ganham muita flexibilidade para implementar métodos mais seguros e práticos para garantir a segurança de usuários. Os métodos mais implementados atualmente incluem a sensores biométricos, senhas ou cartões de identificação RFID(sigla para “Radio Frequency Identification”, significa “identificação por radiofrequência”).
> >
> > Vamos implementar autenticação por aplicativo ou por página web?

> Escreva essa seção imaginando que está tentando convencer alguém a investir financeiramente no seu projeto.
> > A implementação de um sistema de controle de acesso físico é vantajosa pois automatiza o acesso, traz mais segurança na identificação e abre a possibilidade de controlar e monitorar o acesso de maneira remota.
> Qual problema vocês pretendem solucionar?
> > 
> Quem são os potenciais usuários?
> > Empresas de segurança, pessoas físicas, comércios 
> É possível estabelecer um valor econômico associado?


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
> - Deve ser capaz de ler cartões/tags RFID?
> - Deve ser capaz de controlar uma fechadura elétrica ou portão
> - Deve ser capaz de emitir algum sinal que indique que o acesso foi autorizado com sucesso
> 
> 

### Configurabilidade
> Detalhe, se houver, todas as possíveis configurações do circuito e todos os pontos de alteração da configuração.

### Eventos
> Quais eventos o sistema deve tratar?
> Se aplicável, classifique os eventos que são periódicos (procure especificar a periodicidade) e os que são não-periódicos
> (qual o tempo mínimo entre dois eventos sucessivos)?
> 

### Tratamento de Eventos
> Qual comportamento o sistema deve ter para tratar corretamente cada evento?

## Descrição Estrutural do Sistema
> Junto com a descrição do comportamento do sistema, deve-se especificar, em nível de bloco ou sistema, a estrutura necessária 
> para captar os eventos do mundo externo, para alojar e processar o programa de tratamento de eventos, e para atuar sobre o mundo externo.
>
> Para essa descrição recomenda-se a criação de diagramas de blocos.
> Nesse diagrama, devem ser destacados os blocos funcionais que compõem o sistema, incluindo uma síntese das funcionalidades de cada bloco.
> Além disso, deve-se esclarecer também o relacionamento entre estes blocos, incluindo os principais sinais de comunicação entre
> os blocos de forma a assegurar a execução de todas as tarefas que o sistema deve realizar.

> ![Alt](images/someimage.png)
> Você sabia? Ferramentas como o `draw.io` permitem integração com o Github.
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
