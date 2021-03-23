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

$N = 4;  # Número de Repeticiones
@Ejecutable = ("benchmarkCommon","benchmarkPthreads"); # nombre de los ejecutables (benchmarks)
@cores = ("1","2","4","8"); # Número de hilos de ejecución
$rand = 200;
@MatrizSizeOrdinaria = ("400","600","800"); ### Dimensión de la matriz para Ordinaria
@MatrizSizePthreads = ("400","600","800","1000","2000","4000");   ### Dimensión de la matriz para Pthread 
#@MatrizSizePthreads = ("400","600","800","1000");

foreach $size (@MatrizSizeOrdinaria){
     $exe = @Ejecutable[0];
     $file = "$Path/"."soluciones_NGUI/"."$exe"."-Size"."$size"."-rand-"."$rand";
     #print "$file \n";
     for($i=0; $i<$N;  $i++){
	  system("$Path/$exe $size $rand  >> $file");
          #print "$Path/$exe $size $rand\n" ;
     }
     close($file);
}

foreach $size (@MatrizSizePthreads){
     $exe = @Ejecutable[1];
     
     foreach $c (@cores) {
          $file = "$Path/"."soluciones_NGUI/"."$exe"."-Size"."$size"."-cores-"."$c"."-rand-"."$rand";
          #print "$file \n";
          for($i=0; $i<$N;  $i++){
	       system("$Path/$exe $size $c $rand >> $file");
               #print "$Path/$exe $size $c $rand\n" ;
          }
     close($file);
     }
}

	exit(1);
