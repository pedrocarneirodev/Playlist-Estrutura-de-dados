# Playlist com as músicas do arquivo (Simulação)

 Este é um trabalho individual desenvolvido em linguagem C, o qual simula uma playlist com as músicas do arquivo. Para a realização deste projeto foram utilizado conteúdos tanto abordados em sala de aula quanto adquiridos fora dela.

### Funcionalidades:

1. Exibição da playlist pela ordem de cadastro;
2. Exibição da playlist ordenada pelo nome das músicas;
3. Inserção de novas músicas;
4. Remoção de uma música;
5. Busca por uma música;
6. Avançar para próxima música;
7. Retornar a música anterior;

## Como usar

Para compilar o código, abra o terminal do compilador e siga as seguintes instruções:

Clone este repositório, em seguida entre dentro da pasta copiada

```bash
git clone https://github.com/pedrocarneirodev/Simulador-de-Playlist.git
```

Compile:
```
gcc main.c -o output.exe
```

E depois, execute:
```
./output.exe
```
## Correção dos Acentos:

No Powershell, execute o seguinte codigo para resolver problema dos acentos:

```
$OutputEncoding = [console]::InputEncoding = [console]::OutputEncoding =
New-Object System.Text.UTF8Encoding
```

Se for pelo Prompt de comando(CMD), execute o seguinte codigo para resolver problema dos acentos:

```
chcp 65001
```
