function [matched, all_values] = plot_simi_values(simi)

[rows,cols] = size(simi);

all_values = [];
matched = [];
varname = inputname(1);
display(varname);
matching = {{1,15,18,28,31,34,39} %chairs
        {2,14,19,24,27,33,38,42} %bag-book
        {3,5,11,25,29,41} %table
        {4,8,10,13,20,26,30} %cone
        {6,35,36,43} %stool
        {7,9,22,23,32,37,40} %box
        {12} %bag-shop
        {16,17,21}}; %unknown

for i = 1:rows
    for j = 1:cols
        myflag = 0;
        if (j>i)            
            for k = 1:8
                i_find = find([matching{k}{:}] == i);
                j_find = find([matching{k}{:}] == j);
                if (i_find)
                    if (j_find)
                        myflag = 1;
                    end
                end
            end %for k
            if myflag
                matched = [matched; simi(i,j)];
            else
                all_values = [all_values, simi(i,j)];
            end
        end %if
    end %for j
end %for i


figure;
scatter(zeros(length(all_values),1),all_values,'r');
hold on;
scatter(ones(length(matched),1),matched,'g');
%axis([-1,2,0,1]);
xlim([-1,2]);
t=title(varname);
set(t,'Interpreter','none');

end %function