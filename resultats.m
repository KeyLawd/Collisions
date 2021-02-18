clear all; %#ok<CLALL>
close all;

%Utiliser l'outil d'importation pour récupérer resultats.txt
%2 premières lignes : nt = nombre de pas de temps et np = nombre de particules
%Le reste est converti en une matrice resultat : x11 y11 z11 x12 y12 z12
%                                                y21 y21 z21 x22....
%(Chaque ligne est un pas de temps)


fig = figure(1);
Video = VideoWriter('Galaxies');
Video.FrameRate = 15;
open(Video);


nt = dlmread('dimension.txt','',[0 0 0 0])
np = dlmread('dimension.txt','',[1 0 1 0])
xt = zeros(np,1);
yt = zeros(np,1);
zt = zeros(np,1);

for t = 1:nt
    resultat = dlmread('resultat.txt',';',[0 3*(t-1) np-1 3*(t-1)+3]);
    for p = 1:np
        xt = resultat(:,1);
        yt = resultat(:,2);
        zt = resultat(:,3);
        %A cette étape on peut faire le scatterplot
        
    end
    clf;
    axis([-1000 1000 -1000 1000 -1000 1000]);
    
    scatter3(xt,yt,zt);
    shading interp;
    hold on
    if t == 1
        Fsize = 14;
        set(gca,'FontSize',Fsize);
        xlabel('X');
        ylabel('Y');
    end
    figure(1);
    frame = getframe(gcf);
    writeVideo(Video,frame);
    
end