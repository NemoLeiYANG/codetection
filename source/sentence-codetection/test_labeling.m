labels0 = labels_from_avg_similarity_matrix(avg_similarity_matrix0);
labels1 = labels_from_avg_similarity_matrix(avg_similarity_matrix1);
labels2 = labels_from_avg_similarity_matrix(avg_similarity_matrix2);
labels3 = labels_from_avg_similarity_matrix(avg_similarity_matrix3);
labels4 = labels_from_avg_similarity_matrix(avg_similarity_matrix4);
labels5 = labels_from_avg_similarity_matrix(avg_similarity_matrix5);
labels6 = labels_from_avg_similarity_matrix(avg_similarity_matrix6);
labels7 = labels_from_avg_similarity_matrix(avg_similarity_matrix7);
labels8 = labels_from_avg_similarity_matrix(avg_similarity_matrix8);
labels9 = labels_from_avg_similarity_matrix(avg_similarity_matrix9);

numlabels = length(labels0)+length(labels1)+length(labels2)+...
    length(labels3)+length(labels4)+length(labels5)+length(labels6)+...
    length(labels7)+length(labels9)+length(labels9);
display(numlabels);