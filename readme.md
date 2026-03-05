instruções para conseguir ler multiplos arquivos no vscode 

.vscode 

op 1:
"args": [
    "-fcolor-diagnostics",
    "-fansi-escape-codes",
    "-g",
    "${fileDirname}/*.c", // Alteração aqui: compila tudo que termina em .c
    "-o",
    "${fileDirname}/${fileBasenameNoExtension}"
],


op 2 

extenção c/c++ Runner // consegue fazer isso altomaticamnete 


op 3 

manualmente pelo terminal
inclua os arquivos que  quer compilar desse jeito ex : 

gcc main.c pilha.c -o programa(nome que vc quiser) ou gcc *.c -o programa

./programa 