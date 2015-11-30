function bbs = get_proposals(frames,num_proposals)
    [~, ~, ~, T] = size(frames);    
    bbs = zeros(num_proposals,5, T);
    parfor t = 1:T %main parfor loop to do proposals and histogram scores
        img = frames(:,:,:,t);
        bbs(:,:,t) = MCGboxes(img,num_proposals); %proposals
    end %parfor
end %function