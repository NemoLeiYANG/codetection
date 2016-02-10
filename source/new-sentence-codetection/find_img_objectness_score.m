function img_score = find_img_objectness_score(img,box,cues,params)
scores = zeros(1,length(cues));
for i = 1:length(cues)
    foo = computeScores(img,cues{i},params,box);
    scores(i) = foo(5);
end %for i
img_score = integrateBayes(cues,scores,params);
end %function