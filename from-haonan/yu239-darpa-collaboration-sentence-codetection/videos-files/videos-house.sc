;; videos-house1
;;   bowl
;;   cabbage
;;   cleaner
;;   coffee
;;   pineapple
;;   squash

;; videos-house2
;;   bowl
;;   cabbage
;;   cleaner
;;   coffee
;;   pineapple
;;   squash

;; videos-house3
;;   bowl
;;   cabbage
;;   pineapple
;;   squash

;; videos-house4
;;   cup
;;   juice
;;   ketchup
;;   milk

;; videos-house5
;;   box
;;   cooler

;; videos-house6
;;   box
;;   cooler

;; videos-house7
;;   bucket
;;   gas-can
;;   watering-pot

;; videos-house8
;;   bowl
;;   cabbage
;;   pineapple
;;   squash

;; videos-house9
;;   cooler
;;   box
;;   bukect
;;   gas-can
;;   watering-pot

;; videos-house10
;;   bowl
;;   cabbage
;;   cleaner
;;   cup
;;   juice
;;   ketchup
;;   pineapple
;;   milk
  
(("/net/zhineng/aux/yu239/house/00000-000001-000003-bowl.avi"
  ((p put-down #(person 0) #(bowl 0)))
  "the person put the bowl into the sink")
 ("/net/zhineng/aux/yu239/house/00000-000012-000003-cabbage.avi"
  ((v picked-up #(person 0) #(cabbage 0))
   (p in-start #(cabbage 0) #(bowl 0)))
  "the person took the cabbage in the bowl out from the sink and put it on the table")
 ("/net/zhineng/aux/yu239/house/00000-000015-000003-bowl.avi"
  ((v picked-up #(person 0) #(bowl 0)))
  "the person took out the bowl from the sink")
 ("/net/zhineng/aux/yu239/house/00000-000020-000003-squash.avi"
  ((v put-down #(person 0) #(squash 0)))
  "the person put the squash into the sink")
 ("/net/zhineng/aux/yu239/house/00000-000038-000003-pineapple.avi"
  ((v picked-up #(person 0) #(pineapple 0)))
  "the person took the pineapple out from the sink")
 ("/net/zhineng/aux/yu239/house/00000-000044-000003-cabbage.avi"
  ((v put-down #(person 0) #(cabbage 0)))
  "the person put the cabbage into the sink")
 ("/net/zhineng/aux/yu239/house/00000-000051-000003-cleaner.avi"
  ((v put-down #(person 0) #(cleaner 0))
   (p near-end #(cleaner 0) #(cabbage 0)))
  "the person put the cleaner into the sink near the cabbage")
 ("/net/zhineng/aux/yu239/house/00000-000109-000004-coffee.avi"
  ((v put-down #(person 0) #(coffee 0))
   (p above-start #(coffee 0) #(cleaner 0)))
  "the person put the coffee above the cleaner into the sink")
 ("/net/zhineng/aux/yu239/house/00000-000113-000003-cleaner.avi"
  ((v picked-up #(person 0) #(cleaner 0))
   (p near-start #(cleaner 0) #(coffee 0))) 
  "the person took the cleaner near the coffee out from the sink")
 ("/net/zhineng/aux/yu239/house/00000-000146-000003-coffee.avi"
  ((v put-down #(person 0) #(coffee 0)))
  "the person put the coffee into the sink")
 ("/net/zhineng/aux/yu239/house/00000-000156-000003-pineapple.avi"
  ((v moved #(person 0) #(pineapple 0))
   (p in-end #(pineapple 0) #(bowl 0)))
  "the person put the pineapple into the bowl")
 ("/net/zhineng/aux/yu239/house/00000-000204-000002-cleaner.avi"
  ((v picked-up #(person 0) #(cleaner 0))
   (p in-start #(cleaner 0) #(bowl 0)))
  "the person took the cleaner out from the bowl")
 ("/net/zhineng/aux/yu239/house/00000-000210-000003-pineapple.avi"
  ((v put-down #(person 0) #(pineapple 0))
   (p below-end #(pineapple 0) #(cabbage 0)))
  "the person put the pineapple into the sink below the cabbage")
 ("/net/zhineng/aux/yu239/house/00000-000236-000002-pineapple.avi"
  ((v picked-up #(person 0) #(pineapple 0))
   (p to-the-right-of-end #(pineapple 0) #(coffee 0)))
  "the person took the pineapple out from the sink and put it to the right of the coffee")
 ("/net/zhineng/aux/yu239/house/00000-000304-000003-squash.avi"
  ((v picked-up #(person 0) #(squash 0))
   (p near-end  #(squash 0) #(coffee 0)))
  "the person took the squash out from the sink and put it near the coffee")
 ("/net/zhineng/aux/yu239/house/00000-000315-000004-coffee.avi"
  ((v put-down #(person 0) #(coffee 0)))
  "the person put the coffee into the sink")
 ("/net/zhineng/aux/yu239/house/00000-000319-000004-coffee.avi"
  ((v picked-up #(person 0) #(coffee 0)))
  "the person took the coffee out from the sink")
 ("/net/zhineng/aux/yu239/house/00000-000332-000003-pineapple.avi"
  ((v put-down #(person 0) #(pineapple 0))
   (p below-end  #(pineapple 0) #(coffee 0)))
  "the person put the pineapple into the sink below the coffee")
 ("/net/zhineng/aux/yu239/house/00000-000341-000004-squash.avi"
  ((v put-down #(person 0) #(squash 0))
   (p near-start  #(squash 0) #(coffee 0)))
  "the person put the squash near the coffee into the sink")
 ("/net/zhineng/aux/yu239/house/00000-000354-000003-coffee.avi"
  ((v put-down #(person 0) #(coffee 0)))
  "the person put the coffee into the sink")
 ("/net/zhineng/aux/yu239/house/00000-000358-000004-coffee.avi"
  ((v picked-up #(person 0) #(coffee 0)))
  "the person took the coffee out from the sink")
 ("/net/zhineng/aux/yu239/house/00000-000409-000003-cleaner.avi"
  ((v put-down #(person 0) #(cleaner 0))
   (p above-start #(cleaner 0) #(bowl 0))
   (p in-end #(cleaner 0) #(bowl 0)))
  "the person put the cleaner above the bowl into the bowl")
 ("/net/zhineng/aux/yu239/house/00000-000411-000003-cleaner.avi"
  ((p in-start #(cleaner 0) #(bowl 0))
   (p away-from #(cleaner 0) #(bowl 0)))
  "the person took the cleaner in the bowl away from the bowl")
 ("/net/zhineng/aux/yu239/house/00000-000415-000002-pineapple.avi"
  ((v put-down #(person 0) #(pineapple 0)))
  "the person put the pineapple into the sink")
 ("/net/zhineng/aux/yu239/house/00000-000421-000002-cabbage.avi"
  ((v moved #(person 0) #(cabbage 0))
   (p in-end #(cabbage 0) #(bowl 0)))
  "the person put the cabbage in the bowl")
 ("/net/zhineng/aux/yu239/house/00000-000423-000002-cabbage.avi"
  ((v away-from  #(cabbage 0) #(bowl 0)))
  "the person took the cabbage away from the bowl")
;;;;;;;;;;;;;;;;;; scene 00001 ;;;;;;;;;;;;;;;;;;;;;;;;;;
 ("/net/zhineng/aux/yu239/house/00001-000000-000003-bowl.avi"
  ((v carried-leftwards #(person 0) #(bowl 0)))
  "the person moved the bowl from the right counter to the left counter")
 ("/net/zhineng/aux/yu239/house/00001-000004-000003-cleaner.avi"
  ((v carried-leftwards #(person 0) #(cleaner 0)))
  "the person moved the cleaner from the right counter to the left counter")
 ("/net/zhineng/aux/yu239/house/00001-000009-000003-pineapple.avi"
  ((v moved  #(person 0) #(pineapple 0))
   (p to-the-right-of-start #(pineapple 0) #(cleaner 0))
   (p near-end #(pineapple 0) #(cleaner 0)))
  "the person put the pineapple to the right of the cleaner near the cleaner")
 ("/net/zhineng/aux/yu239/house/00001-000014-000003-pineapple.avi"
  ((v carried-rightwards  #(person 0) #(pineapple 0)))
  "the person moved the pineapple from the left counter to the one on the right hand side")
 ("/net/zhineng/aux/yu239/house/00001-000018-000002-cleaner.avi"
  ((v carried-rightwards  #(person 0) #(cleaner 0)))
  "the person moved the cleaner from the left counter to the one on the right hand side")
 ("/net/zhineng/aux/yu239/house/00001-000024-000003-cabbage.avi"
  ((v moved  #(person 0) #(cabbage 0))
   (p to-the-left-of-start #(cabbage 0) #(pineapple 0))
   (p near-end #(cabbage 0) #(cleaner 0)))
  "the person put the cabbage to the left of the pineapple near the cleaner")
 ("/net/zhineng/aux/yu239/house/00001-000031-000003-coffee.avi"
  ((v carried-rightwards  #(person 0) #(coffee 0)))
  "the person carried the coffee rightwards")
 ("/net/zhineng/aux/yu239/house/00001-000043-000003-bowl.avi"
  ((v carried-rightwards #(person 0) #(bowl 0)))
  "the person moved the bowl from the left counter to the right counter")
 ("/net/zhineng/aux/yu239/house/00001-000053-000004-squash.avi"
  ((v carried-rightwards #(person 0) #(squash 0)))
  "the person carried the squash rightwards")
 ("/net/zhineng/aux/yu239/house/00001-000059-000003-squash.avi"
  ((v carried-leftwards #(person 0) #(squash 0)))
  "the person carried the squash leftwards")
 ("/net/zhineng/aux/yu239/house/00001-000132-000003-bowl.avi"
  ((v carried-leftwards #(person 0) #(bowl 0)))
  "the person moved the bowl from the right counter to the one on the left hand side")
 ("/net/zhineng/aux/yu239/house/00001-000136-000003-coffee.avi"
  ((v carried-leftwards #(person 0) #(coffee 0)))
  "the person carried the coffee leftwards")
 ("/net/zhineng/aux/yu239/house/00001-000141-000004-squash.avi"
  ((v away-from #(squash 0) #(coffee 0)))
  "the person took the squash away from the coffee")
 ("/net/zhineng/aux/yu239/house/00001-000150-000002-bowl.avi"
  ((v away-from #(bowl 0) #(coffee 0)))
  "the person took the bowl away from the coffee")
 ("/net/zhineng/aux/yu239/house/00001-000155-000004-squash.avi"
  ((v carried #(person 0) #(squash 0))
   (p to-the-left-of-start #(squash 0) #(pineapple 0))
   (p near-end #(squash 0) #(coffee 0)))
  "the person carried the squash to the left of the pineapple and put it near the coffee")
 ("/net/zhineng/aux/yu239/house/00001-000159-000003-pineapple.avi"
  ((v carried-leftwards #(person 0) #(pineapple 0)))
  "the person carried the pineapple leftwards")
 ("/net/zhineng/aux/yu239/house/00001-000213-000002-pineapple.avi"
  ((v carried-rightwards #(person 0) #(pineapple 0)))
  "the person carried the pineapple rightwards")
 ("/net/zhineng/aux/yu239/house/00001-000219-000002-squash.avi"
  ((v carried-leftwards #(person 0) #(squash 0)))
  "the person carried the squash leftwards")
 ("/net/zhineng/aux/yu239/house/00001-000223-000002-coffee.avi"
  ((v carried-rightwards #(person 0) #(coffee 0))
   (p near-end #(coffee 0) #(pineapple 0)))
  "the person carried the coffee rightwards and put it near the pineapple")
 ("/net/zhineng/aux/yu239/house/00001-000227-000003-cabbage.avi"
  ((v away-from #(cabbage 0) #(squash 0)))
  "the person took the cabbage away from the squash")
 ("/net/zhineng/aux/yu239/house/00001-000233-000002-pineapple.avi"
  ((v away-from #(pineapple 0) #(cabbage 0))
   (p near-end #(pineapple 0) #(squash 0)))
  "the person took the pineapple away from the cabbage and put it near the squash")
 ("/net/zhineng/aux/yu239/house/00001-000238-000002-squash.avi"
  ((v carried-rightwards #(person 0) #(squash 0))
   (p near-end #(squash 0) #(cabbage 0)))
  "the person carried the squash rightwards and put it near the cabbage")
 ("/net/zhineng/aux/yu239/house/00001-000256-000003-pineapple.avi"
  ((v carried-rightwards #(person 0) #(pineapple 0)))
  "the person moved the pineapple from the left counter to the right counter")
 ("/net/zhineng/aux/yu239/house/00001-000317-000002-bowl.avi"
  ((v moved #(person 0) #(bowl 0))
   (p near-end #(bowl 0) #(coffee 0)))
  "the person put the bowl near the coffee")
 ("/net/zhineng/aux/yu239/house/00001-000348-000002-bowl.avi"
  ((v moved #(person 0) #(bowl 0))
   (p near-end #(bowl 0) #(cleaner 0)))
  "the person put the bowl near the cleaner")
 ("/net/zhineng/aux/yu239/house/00001-000400-000003-pineapple.avi"
  ((v carried-leftwards #(person 0) #(pineapple 0)))
  "the person moved the pineapple from the right counter to the one on the left hand side")
 ("/net/zhineng/aux/yu239/house/00001-000408-000003-coffee.avi"
  ((v carried-rightwards #(person 0) #(coffee 0))
   (p to-the-right-of-start #(coffee 0) #(cabbage 0)))
  "the person carried the coffee which is to the right of the cabbage rightwards")
 ("/net/zhineng/aux/yu239/house/00001-000426-000002-squash.avi"
  ((v carried-rightwards #(person 0) #(squash 0)))
  "the person carried the squash rightwards")
 ("/net/zhineng/aux/yu239/house/00001-000437-000003-coffee.avi"
  ((v carried-leftwards #(person 0) #(coffee 0)))
  "the person moved the coffee from the right counter to the one on the left hand side")
 ("/net/zhineng/aux/yu239/house/00001-000442-000002-pineapple.avi"
  ((v moved #(person 0) #(pineapple 0))
   (p near-end #(pineapple 0) #(coffee 0)))
  "the person put the pineapple near the coffee")
 ("/net/zhineng/aux/yu239/house/00001-000507-000002-cleaner.avi"
  ((v moved #(person 0) #(cleaner 0))
   (p near-end #(cleaner 0) #(coffee 0)))
  "the person put the cleaner near the coffee")
 ("/net/zhineng/aux/yu239/house/00001-000509-000003-cleaner.avi"
  ((v carried-rightwards #(person 0) #(cleaner 0)))
  "the person moved the cleaner from the left counter to the one on the right hand side")
 ;; scene 3
 ("/net/zhineng/aux/yu239/house/00002-000006-000003-cabbage.avi"
  ((v moved #(person 0) #(cabbage 0))
   (p in-start #(cabbage 0) #(bowl 0))
   (p away-from #(cabbage 0) #(bowl 0)))
  "the person took the cabbage out from the bowl")
 ("/net/zhineng/aux/yu239/house/00002-000016-000005-pineapple.avi"
  ((v moved #(person 0) #(pineapple 0))
   (p to-the-left-of-start #(pineapple 0) #(bowl 0))
   (p towards #(pineapple 0) #(bowl 0))
   (p in-end #(pineapple 0) #(bowl 0)))
  "the person put the pineapple to the left of the bowl in the bowl")
 ("/net/zhineng/aux/yu239/house/00002-000037-000003-squash.avi"
  ((v moved #(person 0) #(squash 0))
   (p to-the-right-of-start #(squash 0) #(bowl 0))
   (p towards #(squash 0) #(bowl 0))
   (p in-end #(squash 0) #(bowl 0)))
  "the person put the squash to the right of the bowl in the bowl")
 ("/net/zhineng/aux/yu239/house/00002-000041-000002-squash.avi"
  ((v moved #(person 0) #(squash 0))
   (p away-from #(squash 0) #(bowl 0))
   (p in-start #(squash 0) #(bowl 0)))
  "the person took the squash out from the bowl")
 ("/net/zhineng/aux/yu239/house/00002-000056-000002-pineapple.avi"
  ((v moved #(person 0) #(pineapple 0))
   (p towards #(pineapple 0) #(bowl 0))
   (p in-end #(pineapple 0) #(bowl 0)))
  "the person put the pineapple in the bowl")
 ("/net/zhineng/aux/yu239/house/00002-000058-000002-pineapple.avi"
  ((v moved #(person 0) #(pineapple 0))
   (p away-from #(pineapple 0) #(bowl 0))
   (p in-start #(pineapple 0) #(bowl 0)))
  "the person took the pineapple out from the bowl")
 ("/net/zhineng/aux/yu239/house/00002-000112-000002-squash.avi"
  ((v moved #(person 0) #(squash 0))
   (p away-from #(squash 0) #(bowl 0))
   (p in-start #(squash 0) #(bowl 0)))
  "the person took the squash out from the bowl")
 ("/net/zhineng/aux/yu239/house/00002-000120-000002-cabbage.avi"
  ((v moved #(person 0) #(cabbage 0))
   (p towards #(cabbage 0) #(bowl 0))
   (p in-end #(cabbage 0) #(bowl 0)))
  "the person put the cabbage in the bowl")
 ("/net/zhineng/aux/yu239/house/00002-000123-000002-cabbage.avi"
  ((v moved #(person 0) #(cabbage 0))
   (p away-from #(cabbage 0) #(bowl 0))
   (p in-start #(cabbage 0) #(bowl 0)))
  "the person took the cabbage out from the bowl")
 ("/net/zhineng/aux/yu239/house/00002-000143-000002-cabbage.avi"
  ((v moved #(person 0) #(cabbage 0))
   (p towards #(cabbage 0) #(bowl 0))
   (p in-end #(cabbage 0) #(bowl 0)))
  "the person put the cabbage in the bowl")
 ("/net/zhineng/aux/yu239/house/00002-000147-000002-cabbage.avi"
  ((v moved #(person 0) #(cabbage 0))
   (p away-from #(cabbage 0) #(bowl 0))
   (p in-start #(cabbage 0) #(bowl 0)))
  "the person took the cabbage out from the bowl")
 ("/net/zhineng/aux/yu239/house/00002-000154-000002-pineapple.avi"
  ((v moved #(person 0) #(pineapple 0))
   (p towards #(pineapple 0) #(bowl 0))
   (p in-end #(pineapple 0) #(bowl 0)))
  "the person put the pineapple in the bowl")
 ;; scene 4
 ("/net/zhineng/aux/yu239/house/00003-000002-000003-ketchup.avi"
  ((p above-any #(ketchup 0) #(cup 0))
   (v rotated #(person 0) #(ketchup 0)))
  "the person poured the ketchup into the cup")
 ("/net/zhineng/aux/yu239/house/00003-000014-000004-milk.avi"
  ((p above-any #(milk 0) #(cup 0))
   (v rotated #(person 0) #(milk 0)))
  "the person poured the milk into the cup")
 ("/net/zhineng/aux/yu239/house/00003-000036-000004-juice.avi"
  (;;(p to-the-right-of-start #(juice 0) #(wine 0))
   (p above-any #(juice 0) #(cup 0))
   (v rotated #(person 0) #(juice 0)))
  "the person poured the juice into the cup")
 ("/net/zhineng/aux/yu239/house/00003-000059-000004-juice.avi"
  ((p above-any #(juice 0) #(cup 0))
   (v rotated #(person 0) #(juice 0)))
  "the person poured the juice into the cup")
 ("/net/zhineng/aux/yu239/house/00003-000107-000003-milk.avi"
  ((p to-the-left-of-start #(milk 0) #(juice 0))
   (p above-any #(milk 0) #(cup 0))
   (v rotated #(person 0) #(milk 0)))
  "the person poured the milk into the cup to the left of the juice")
 ("/net/zhineng/aux/yu239/house/00003-000118-000004-ketchup.avi"
  ((p above-any #(ketchup 0) #(cup 0))
   (v rotated #(person 0) #(ketchup 0)))
  "the person poured the ketchup into the cup")
 ("/net/zhineng/aux/yu239/house/00003-000143-000003-ketchup.avi"
  ((p above-any #(ketchup 0) #(cup 0))
   (v rotated #(person 0) #(ketchup 0)))
  "the person added some ketchup into the cup")
 ("/net/zhineng/aux/yu239/house/00003-000153-000003-milk.avi"
  ((p above-any #(milk 0) #(cup 0))
   (v rotated #(person 0) #(milk 0))
   (p to-the-left-of #(cup 0) #(cup 1)))
  "the person added some milk into the cup to the left of the cup")
 ("/net/zhineng/aux/yu239/house/00003-000245-000004-ketchup.avi"
  ((p above-any #(ketchup 0) #(cup 0))
   (v rotated #(person 0) #(ketchup 0)))
  "the person added some ketchup into the cup")
 ("/net/zhineng/aux/yu239/house/00003-000306-000004-juice.avi"
  ((p above-any #(juice 0) #(cup 0))
   (v rotated #(person 0) #(juice 0)))
  "the person poured some juice into the cup")
 ("/net/zhineng/aux/yu239/house/00003-000336-000004-milk.avi"
  (;;(p to-the-right-of-start #(milk 0) #(wine 0))
   (v rotated #(person 0) #(milk 0)))
  "the person poured the milk")
 ("/net/zhineng/aux/yu239/house/00003-000346-000003-ketchup.avi"
  ((p to-the-right-of-start #(ketchup 0) #(milk 0))
   (v rotated #(person 0) #(ketchup 0)))
  "the person poured the ketchup to the right of the milk")
 ("/net/zhineng/aux/yu239/house/00003-000350-000004-juice.avi"
  ((p above-any #(juice 0) #(cup 0))
   (v rotated #(person 0) #(juice 0)))
  "the person poured the juice into the cup")
 ("/net/zhineng/aux/yu239/house/00003-000418-000004-ketchup.avi"
  ((p to-the-left-of-start #(ketchup 0) #(juice 0))
   (v rotated #(person 0) #(ketchup 0)))
  "the person poured the ketchup to the left of the juice")
 ("/net/zhineng/aux/yu239/house/00003-000424-000003-juice.avi"
  ((p to-the-right-of-start #(juice 0) #(ketchup 0))
   (v rotated #(person 0) #(juice 0)))
  "the person poured the juice to the right of the ketchup")
 ("/net/zhineng/aux/yu239/house/00003-000459-000004-ketchup.avi"
  ((p above-any #(ketchup 0) #(cup 0))
   (v rotated #(person 0) #(ketchup 0))
   (p to-the-left-of #(cup 0) #(cup 1)))
  "the person added some ketchup into the cup to the left of the cup")
 ("/net/zhineng/aux/yu239/house/00003-000508-000005-milk.avi"
  ((p above-any #(milk 0) #(cup 0))
   (v rotated #(person 0) #(milk 0))
   (p to-the-left-of #(cup 0) #(cup 1)))
  "the person added some milk into the cup to the left of the cup")
 ("/net/zhineng/aux/yu239/house/00003-000518-000004-juice.avi"
  ((p above-any #(juice 0) #(cup 0))
   (v rotated #(person 0) #(juice 0))
   (p to-the-right-of #(cup 0) #(cup 1)))
  "the person added some juice into the cup to the right of the cup")
 ("/net/zhineng/aux/yu239/house/00003-000540-000003-milk.avi"
  ((p above-any #(milk 0) #(cup 0))
   (v rotated #(person 0) #(milk 0))
   (p to-the-right-of #(cup 0) #(cup 1)))
  "the person added some milk into the cup to the right of the cup")
 ("/net/zhineng/aux/yu239/house/00003-000548-000002-ketchup.avi"
  ((p above-any #(ketchup 0) #(cup 0))
   (v rotated #(person 0) #(ketchup 0))
   (p to-the-right-of #(cup 0) #(cup 1)))
  "the person added some ketchup into the cup to the right of the cup")
 ("/net/zhineng/aux/yu239/house/00003-000600-000004-juice.avi"
  ((p above-any #(juice 0) #(cup 0))
   (v rotated #(person 0) #(juice 0))
   (p to-the-left-of #(cup 0) #(cup 1)))
  "the person added some juice into the cup to the left of the cup")
 ;; scene 5
 ("/net/zhineng/aux/yu239/house/00004-000006-000003-cooler.avi"
  ((v picked-up #(person 0) #(cooler 0)))
  "the person lifted the cooler onto the table")
 ("/net/zhineng/aux/yu239/house/00004-000012-000002-cooler.avi"
  ((v put-down #(person 0) #(cooler 0)))
  "the person put down the cooler on the ground")
 ("/net/zhineng/aux/yu239/house/00004-000028-000003-cooler.avi"
  ((v picked-up #(person 0) #(cooler 0))
   (p to-the-right-of-start #(cooler 0) #(cooler 1)))
  "the person lifted the cooler to the right of the cooler")
 ("/net/zhineng/aux/yu239/house/00004-000035-000003-box.avi"
  ((v picked-up #(person 0) #(box 0))
   (p below-start #(box 0) #(cooler 0)))
  "the person picked up the box below the cooler")
 ("/net/zhineng/aux/yu239/house/00004-000040-000002-box.avi"
  ((v put-down #(person 0) #(box 0)))
  "the person put down the box on the ground")
 ("/net/zhineng/aux/yu239/house/00004-000104-000002-cooler.avi"
  ((v put-down #(person 0) #(cooler 0)))
  "the person put down the cooler")
 ("/net/zhineng/aux/yu239/house/00004-000156-000002-cooler.avi"
  ((v moved #(person 0) #(cooler 0))
   (p on-top-of-end #(cooler 0) #(cooler 1)))
  "the person stacked the cooler onto the cooler")
 ("/net/zhineng/aux/yu239/house/00004-000158-000004-cooler.avi"
  ((v put-down #(person 0) #(cooler 0))
   (p on-top-of-end #(cooler 0) #(cooler 1)))
  "the person put down the cooler on top of the cooler")
 ("/net/zhineng/aux/yu239/house/00004-000210-000002-cooler.avi"
  ((v moved #(person 0) #(cooler 0))
   (p on-top-of-end #(cooler 0) #(cooler 1)))
  "the person stacked the cooler onto the cooler")
 ("/net/zhineng/aux/yu239/house/00004-000236-000003-cooler.avi"
  ((v picked-up #(person 0) #(cooler 0))
   (p on-top-of-end #(cooler 0) #(box 0)))
  "the person picked up the cooler and put it on top of the box")
 ("/net/zhineng/aux/yu239/house/00004-000320-000004-box.avi"
  ((v carried-leftwards #(person 0) #(box 0)))
  "the person carried the box leftwards")
 ("/net/zhineng/aux/yu239/house/00004-000438-000003-box.avi"
  ((v carried-leftwards #(person 0) #(box 0)))
  "the person carried the box leftwards")
 ("/net/zhineng/aux/yu239/house/00004-000447-000003-box.avi"
  ((v carried-leftwards #(person 0) #(box 0)))
  "the person carried the box leftwards")
 ("/net/zhineng/aux/yu239/house/00004-000450-000002-box.avi"
  ((v picked-up #(person 0) #(box 0)))
  "the person picked up the box")
 ("/net/zhineng/aux/yu239/house/00004-000457-000002-box.avi"
  ((v put-down #(person 0) #(box 0)))
  "the person put down the box")
 ("/net/zhineng/aux/yu239/house/00004-000508-000003-box.avi"
  ((v carried-leftwards #(person 0) #(box 0)))
  "the person carried the box leftwards")
 ("/net/zhineng/aux/yu239/house/00004-000520-000003-cooler.avi"
  ((v moved #(person 0) #(cooler 0))
   (p near-end #(cooler 0) #(box 0)))
  "the person put the cooler near the box")
 ("/net/zhineng/aux/yu239/house/00004-000527-000002-cooler.avi"
  ((p near-start #(cooler 0) #(box 0)))
  "the person took the cooler away from the box")
 ("/net/zhineng/aux/yu239/house/00004-000529-000002-cooler.avi"
  ((v moved #(person 0) #(cooler 0))
   (p on-top-of-end #(cooler 0) #(box 0)))
  "the person stacked the cooler onto the box")
 ("/net/zhineng/aux/yu239/house/00005-000001-000003-cooler.avi"
  ((v put-down #(person 0) #(cooler 0))
   (p to-the-right-of-start #(cooler 0) #(box 0))) 
  "the person put down the cooler to the right of the box")
 ("/net/zhineng/aux/yu239/house/00005-000004-000003-box.avi"
  ((v put-down #(person 0) #(box 0))
   (p above-start #(box 0) #(cooler 0)))
  "the person put down the box above the cooler")
 ("/net/zhineng/aux/yu239/house/00005-000029-000002-box.avi"
  ((v picked-up #(person 0) #(box 0))
   ;;(p to-the-right-of-start #(box 0) #(toy 0))
   )
  "the person lifted the box")
 ("/net/zhineng/aux/yu239/house/00005-000032-000003-cooler.avi"
  ((v picked-up #(person 0) #(cooler 0))
   (p on-top-of-end #(cooler 0) #(box 0)))
  "the person lifted the cooler and stacked it onto the box")
 ("/net/zhineng/aux/yu239/house/00005-000100-000002-cooler.avi"
  ((v picked-up #(person 0) #(cooler 0)))
  "the person picked up the cooler")
 ("/net/zhineng/aux/yu239/house/00005-000204-000002-cooler.avi"
  ((v carried-rightwards #(person 0) #(cooler 0)))
  "the person carried the cooler rightwards")
 ("/net/zhineng/aux/yu239/house/00005-000214-000002-box.avi"
  ((v put-down #(person 0) #(box 0)))
  "the person put down the box")
 ("/net/zhineng/aux/yu239/house/00005-000252-000002-cooler.avi"
  ((v picked-up #(person 0) #(cooler 0))
   (p on-top-of-start #(cooler 0) #(box 0)))
  "the person picked up the cooler on top of the box")
 ("/net/zhineng/aux/yu239/house/00005-000255-000002-box.avi"
  ((v picked-up #(person 0) #(box 0)))
  "the person picked up the box")
 ("/net/zhineng/aux/yu239/house/00005-000306-000003-cooler.avi"
  ((v moved #(person 0) #(cooler 0))
   (p on-top-of-end #(cooler 0) #(cooler 1)))
  "the person stacked the cooler onto the cooler")
 ("/net/zhineng/aux/yu239/house/00005-000339-000002-box.avi"
  ((v put-down #(person 0) #(box 0))
   (p to-the-right-of-start #(box 0) #(cooler 0)))  
  "the person put down the box to the right of the cooler")
 ("/net/zhineng/aux/yu239/house/00005-000403-000002-box.avi"
  ((v carried-rightwards #(person 0) #(box 0)))
  "the person carried the box rightwards")
 ("/net/zhineng/aux/yu239/house/00005-000614-000003-cooler.avi"
  ((v picked-up #(person 0) #(cooler 0)))
  "the person picked up the cooler")
 ("/net/zhineng/aux/yu239/house/00005-000641-000003-cooler.avi"
  ((v put-down #(person 0) #(cooler 0)))
  "the person put down the cooler")
 ("/net/zhineng/aux/yu239/house/00006-000027-000003-box.avi"
  ((v put-down #(person 0) #(box 0))
   ;;(p to-the-right-of-start #(box 0) #(toy 0))
   )
  "the person put down the box")
 ("/net/zhineng/aux/yu239/house/00006-000042-000002-cooler.avi"
  ((v carried-leftwards #(person 0) #(cooler 0)))
  "the person carried the cooler leftwards")
 ("/net/zhineng/aux/yu239/house/00006-000049-000002-cooler.avi"
  ((v carried-rightwards #(person 0) #(cooler 0)))
  "the person carried the cooler rightwards")
 ;;;;;;;;;;;;;;;;;;;;;;;;; scene 00008 ;;;;;;;;;;;;;;;;;;;;;;;;;;
 ("/net/zhineng/aux/yu239/house/00008-000014-000003-watering-pot.avi"
  ((v picked-up #(person 0) #(watering-pot 0)))
  "the person loaded the watering-pot into the trunk")
 ("/net/zhineng/aux/yu239/house/00008-000017-000002-watering-pot.avi"
  ((v put-down #(person 0) #(watering-pot 0))
   )
  "the person unloaded the watering-pot from the trunk")
 ("/net/zhineng/aux/yu239/house/00008-000049-000002-bucket.avi"
  ((v picked-up #(person 0) #(bucket 0)))
  "the person loaded the bucket into the trunk")
 ("/net/zhineng/aux/yu239/house/00008-000051-000003-bucket.avi"
  ((v put-down #(person 0) #(bucket 0)))
  "the person unloaded the bucket from the trunk")
 ("/net/zhineng/aux/yu239/house/00008-000102-000003-bucket.avi"
  ((v picked-up #(person 0) #(bucket 0))
   )
  "the person picked up the bucket")
 ("/net/zhineng/aux/yu239/house/00008-000105-000002-bucket.avi"
  ((v put-down #(person 0) #(bucket 0)))  
  "the person put down the bucket on the ground")
 ("/net/zhineng/aux/yu239/house/00008-000109-000002-gas-can.avi"
  ((v put-down #(person 0) #(gas-can 0))
   (p to-the-left-of-end #(gas-can 0) #(bucket 0)))
  "the person unloaded the gas-can from the trunk and put it to the left of the bucket")
 ("/net/zhineng/aux/yu239/house/00008-000113-000004-watering-pot.avi"
  ((v put-down #(person 0) #(watering-pot 0))
   (p above-start #(watering-pot 0) #(gas-can 0)))
  "the person put down the watering-pot above the gas-can")
 ("/net/zhineng/aux/yu239/house/00008-000158-000003-bucket.avi"
  ((v picked-up #(person 0) #(bucket 0))
   (p to-the-right-of-start #(bucket 0) #(gas-can 0)))
  "the person loaded the bucket to the right of the gas-can into the trunk")
 ("/net/zhineng/aux/yu239/house/00008-000218-000002-gas-can.avi"
  ((v put-down #(person 0) #(gas-can 0)))  
  "the person unloaded the gas-can from the trunk")
 ("/net/zhineng/aux/yu239/house/00008-000320-000003-bucket.avi"
  ((v picked-up #(person 0) #(bucket 0))
   (p to-the-left-of-start #(bucket 0) #(gas-can 0)))  
  "the person loaded the bucket to the left of the gas-can into the trunk")
 ("/net/zhineng/aux/yu239/house/00008-000325-000003-gas-can.avi"
  ((v picked-up #(person 0) #(gas-can 0))
   (p near-end #(gas-can 0) #(bucket 0)))    
  "the person picked up the gas-can and put it near the bucket")
 ("/net/zhineng/aux/yu239/house/00008-000337-000002-gas-can.avi"
  ((v put-down #(person 0) #(gas-can 0))
   )
  "the person unloaded the gas-can from the trunk")
 ("/net/zhineng/aux/yu239/house/00008-000340-000002-bucket.avi"
  ((v put-down #(person 0) #(bucket 0))
   (p near-end #(bucket 0) #(gas-can 0)))
  "the person unloaded the bucket and put it near the gas-can")
 ("/net/zhineng/aux/yu239/house/00008-000439-000002-watering-pot.avi"
  ((v picked-up #(person 0) #(watering-pot 0))
   (p to-the-left-of-start #(watering-pot 0) #(bucket 0)))
  "the person picked up the watering-pot to the left of the bucket")
 ("/net/zhineng/aux/yu239/house/00008-000449-000002-watering-pot.avi"
  ((v put-down #(person 0) #(watering-pot 0))
   )
  "the person put down the watering-pot")
 ("/net/zhineng/aux/yu239/house/00008-000514-000002-watering-pot.avi"
  ((v carried-rightwards #(person 0) #(watering-pot 0)))    
  "the person carried the watering-pot rightwards")
 ("/net/zhineng/aux/yu239/house/00008-000524-000002-bucket.avi"
  ((v carried-leftwards #(person 0) #(bucket 0)))    
  "the person carried the bucket leftwards")
 ("/net/zhineng/aux/yu239/house/00008-000528-000002-bucket.avi"
  ((v carried-rightwards #(person 0) #(bucket 0)))      
  "the person carried the bucket rightwards")
 ("/net/zhineng/aux/yu239/house/00008-000603-000003-watering-pot.avi"
  ((v picked-up #(person 0) #(watering-pot 0)))    
  "the person picked up the watering-pot")
 ("/net/zhineng/aux/yu239/house/00008-000637-000002-gas-can.avi"
  ((v put-down #(person 0) #(gas-can 0)))      
  "the person unloaded the gas-can from the trunk")
 ("/net/zhineng/aux/yu239/house/00008-000640-000003-bucket.avi"
  ((v put-down #(person 0) #(bucket 0))
   (p near-end #(bucket 0) #(gas-can 0)))      
  "the person unloaded the bucket from the trunk and put it near the gas-can")
 ("/net/zhineng/aux/yu239/house/00008-000644-000002-watering-pot.avi"
  ((v put-down #(person 0) #(watering-pot 0))
   (p near-end #(watering-pot 0) #(bucket 0)))        
  "the person unloaded the watering-pot and put it near the bucket")
 )