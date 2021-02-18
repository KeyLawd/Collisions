clear all; %#ok<CLALL>
close all;

%Utiliser l'outil d'importation pour r�cup�rer resultats.txt
%2 premi�res lignes : nt = nombre de pas de temps et np = nombre de particules
%Le reste est converti en une matrice resultat : x11 y11 z11 x12 y12 z12
%                                                y21 y21 z21 x22....
%(Chaque ligne est un pas de temps)

%Coordonn�es des particules � un instant t
nt = dlmread('dimension.txt','',[0 0 0 0])
np = dlmread('dimension.txt','',[1 0 1 0])
xt = zeros(np,1);
yt = zeros(np,1);
zt = zeros(np,1);

for t = 1:nt
    resultat = dlmread('resultat.txt',';',[0 3*(t-1) np-1 3*(t-1)+3])
    for p = 1:np
        xt = resultat(:,1);
        yt = resultat(:,2);
        zt = resultat(:,3);
        %A cette �tape on peut faire le scatterplot             
    end 
    scatter3(xt,yt,zt);
end