/*
16. На предприятии есть n𝑛 (2 ≤ n ≤ 10000) отделов, между которыми нужно проложить сеть. Есть m (2 ≤ m ≤ 100000) 
вариантов для соединения отделов между собой, описываемых тройкой ai, bi, di, где ai, bi - номера отделов, 
di - длина кабеля. Для построения сети необходимо, чтобы все отделы прямо или косвенно через другие отделы 
были соединены между собой.
Укажите какой алгоритм построения минимального остовного дерева является более эффективным для решения этой 
задачи и обоснуйте свой выбор.

Я знаю всего 2 алгоритма для построения остовного дерева – Алгоритм Прима и Крускала.
Алгоритм Прима более эффективен когда граф насыщен (то есть количество ребер ~ квадрату количества вершин), 
а Алгоритм Крускала наоборот более эффективен на разреженных графах (то есть количество ребер ~ количества вершин).

В данном случае лучше использовать Алгоритм Крускала.

*/