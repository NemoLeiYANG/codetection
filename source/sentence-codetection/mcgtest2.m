% enable parfor
pools = matlabpool('size');
cpus = feature('numCores');
if pools ~= (cpus - 1)
    if pools > 0
        matlabpool('close');
    end
    matlabpool('open', cpus - 1);
end
%add necessary path
addpath(genpath('MCG-PreTrained'));

%imnum = 18;
numboxes = 100;
[~,~,~,numframes] = size(frames);
tic;
outboxes = zeros(numboxes,5,numframes);
parfor i = 1:numframes
    outboxes(:,:,i) = MCGboxes(frames(:,:,:,i),numboxes);
end %parfor
toc;