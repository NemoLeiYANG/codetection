function bbs = get_proposals_edgeboxes(frames,num_proposals)
    model=load('/home/sbroniko/codetection/source/new-sentence-codetection/forests_edges_boxes/models/forest/modelBsds.mat');
    model=model.model;
    [~, ~, ~, T] = size(frames);    
    bbs = zeros(num_proposals,5, T);
    parfor t = 1:T %main parfor loop to do proposals and histogram scores
        img = frames(:,:,:,t);
        temp_boxes = edgeBoxes(img,model); %proposals
        bbs(:,:,t) = temp_boxes(1:num_proposals,:);
    end %parfor
end %function