#!/usr/bin/perl   
#En Perl, el encabezado debe ir siempre de esa forma
#el encabezado /usr/bin/perl ubicar el compilador e interprete de PERL

######################
# Fecha: 16_02_2021
# Asignatura: Computación Paralela y Distribuida 
# Ciencias de la Computación
# Asunto: Programa que permite hacer lanzamiento automático de una Bateria de Experimentos
######################
$path0 = `pwd`;
chomp($path0);
$T = index($path0,"T")-1;
#$Path = substr($path0,0,$T);
$Path = $path0;
# print "$Path \n";
$N = 4;  # Número de Repeticiones
@benchmarks = ("benchmarkConventional","benchmarkPthreads","benchmarkTranspose","benchmarkTranspose2","benchmarkTransposeDynamic"); # nombre de los ejecutables (benchmarks)
# @benchmarks = ("benchmarkConventional"); # nombre de los ejecutables (benchmarks)
@cores = ("1","2","4","8"); # Número de hilos de ejecución
# $rand = 200;
@sizes = ("600","800","1000","2000","4000","6000");   ### Dimensión de la matriz para Pthread 
# @sizes = ("200","400");   ### Dimensión de la matriz para Pthread 
# @sizes = ("64","120","200");   ### Dimensión de la matriz para Pthread 

#@MatrizSizePthreads = ("400","600","800","1000");
foreach $benchmark (@benchmarks){
  
  foreach $size (@sizes){

     $exe = $benchmark;
     
     foreach $c (@cores) {


      $file = "sols/$exe".".csv";
    #  $file = "$Path/"."outputs/"."$exe"."-Size"."$size"."-.csv";
    #  print "file: $file \n";
	  system("echo $exe-Size-$size-cores-$c >> $file");
     for($i=0; $i<$N;  $i++){
    #  print "Entra \n";
    #  print "$Path/$exe $size $c \n";
	  system("$Path/$exe $size $c >> $file");
          #print "$Path/$exe $size $rand\n" ;
     }
	  system("echo >> $file");
     close($file);
     }
  }
}



	exit(0);
