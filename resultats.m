clear all; %#ok<CLALL>
close all;

 writerObj = VideoWriter('resultat.avi');
 writerObj.FrameRate = 5;
 open(writerObj);
 axis([-1000 1000 -1000 1000]);

nt = dlmread('dimension.txt','',[0 0 0 0])
np = dlmread('dimension.txt','',[1 0 1 0])
xt = zeros(np,1);
yt = zeros(np,1);
zt = zeros(np,1);

for t = 2:nt

    resultat = dlmread('resultat.txt',';',[0 3*(t-1) np-1 3*(t-1)+3]);
    for p = 1:np
        xt = resultat(:,1);
        yt = resultat(:,2);
        %zt = resultat(:,3);
        %A cette étape on peut faire le scatterplot
        
    end
    clf;%Clear current figure    
    scatter(xt,yt,'+');
    %scatter3(xt,yt,zt);
    axis([-1000 1000 -1000 1000]);
    title(t);
    shading interp;
    hold on
    if t == 1
        Fsize = 14;
        set(gca,'FontSize',Fsize);
        xlabel('X');
        ylabel('Y');
    end
    %figure(1);
    frame = getframe;
    writeVideo(writerObj, frame);
end
close(writerObj);