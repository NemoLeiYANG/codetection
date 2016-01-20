fid = fopen('/aux/dpbarret/vader-rover/logs/2014-07-24-18:16:58/imu-log.txt')
tline = fgets(fid)
i=1;
S(1)=0;
while (~isempty(tline) && isa(tline,'char'))
    disp('read a line')
    items= sscanf(tline,...
    '%lf: EIS:IMU:time:%u:dt:%u:Y:%f:P:%f:R:%f:Y(a):%f:M_h(a):%f:M_h:%f:Ax:%f:Ay:%f:Az:%f:Mx:%f:My:%f:Mz:%f:Gx:%f:Gy:%f:Gz:%f:ENC:time:%u:dt:%u:L:%f:R:%f')
    if (length(items)==22)
        data(i,:)=items;
        
        S(i+1)=S(i)+(data(i,10)-1)*(1/50);
        i=i+1;
    end
    
    tline = fgets(fid)
end
fclose(fid)

plot(data(:,2),data(:,4),'.-',data(:,2),data(:,5),'.-',data(:,2),data(:,6),'.-',data(:,2),data(:,9),'.-',data(:,2),data(:,18)/10,'.-'); legend({'Y','P','R','Mh','Gz'})
figure
plot(data(:,1),data(:,21)*100,'-',data(:,1),data(:,22)*100,'-',data(:,1),data(:,4),'-',data(:,1),data(:,10),'-',data(:,1),data(:,18)/10,'-'); legend({'L','R','Y','Ax','Gz'})
figure 
plot(data(:,1),S(1:end-1),data(:,1),data(:,10)-1)
legend({'integrated ax','ax'})