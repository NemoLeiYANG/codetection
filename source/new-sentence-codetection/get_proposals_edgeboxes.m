function bbs = get_proposals_edgeboxes(frames,num_proposals)
    model=load('/home/sbroniko/codetection/source/new-sentence-codetection/forests_edges_boxes/models/forest/modelBsds.mat');
    model=model.model;
    [~, ~, ~, T] = size(frames);    
    bbs = zeros(num_proposals,5, T);
    rand('seed',sum(100*clock));
    randnum = randi(1000);
    fname = sprintf('/tmp/scott-%d.txt',randnum);
    fh = fopen(fname,'w');
    fprintf(fh,'starting parfor\n');
    parfor t = 1:T %main parfor loop to do proposals and histogram scores
        %fprintf(fh,'start iteration %d\n',t);
        img = frames(:,:,:,t);
        temp_boxes = edgeBoxes(img,model); %proposals
        [numrows,~] = size(temp_boxes);
        tempbbs = zeros(num_proposals,5);
        if (numrows >= num_proposals)
            tempbbs = temp_boxes(1:num_proposals,:);
        else
            tempbbs(1:numrows,:) = temp_boxes(1:numrows,:);
        end %if
        bbs(:,:,t) = tempbbs;
        %fprintf(fh,'end iteration %d\n',t);
    end %parfor
    fprintf(fh,'get_proposals_edgeboxes complete\n');
    fclose(fh);
end %function