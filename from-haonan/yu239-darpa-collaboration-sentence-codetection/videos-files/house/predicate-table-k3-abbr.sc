(((("00000-000001-000003-bowl" "person put bowl in sink")
    ("00000-000001-000003-bowl" "person put bowl in sink")
    ("00000-000020-000003-squash" "person put squash in sink")
    ("00000-000020-000003-squash" "person put squash in sink")
    ("00000-000044-000003-cabbage" "person put cabbage in sink")
    ("00000-000044-000003-cabbage" "person put cabbage in sink")
    ("00000-000051-000003-cleaner" "person put cleaner in sink")
    ("00000-000051-000003-cleaner" "person put cleaner in sink")
    ("00000-000109-000004-coffee" "person put coffee in sink")
    ("00000-000109-000004-coffee" "person put coffee in sink")
    ("00000-000146-000003-coffee" "person put coffee in sink")
    ("00000-000146-000003-coffee" "person put coffee in sink")
    ("00000-000210-000003-pineapple" "person put pineapple in sink")
    ("00000-000315-000004-coffee" "person put coffee in sink")
    ("00000-000332-000003-pineapple" "person put pineapple in sink")
    ("00000-000341-000004-squash" "person put squash in sink")
    ("00000-000354-000003-coffee" "person put coffee in sink")
    ("00002-000056-000002-pineapple" "person put pineapple in sink")
    ("00002-000120-000002-cabbage" "person put cabbage in sink")
    ("00002-000154-000002-pineapple" "person put pineapple in sink"))
   (X0 PUT X1 IN SINK)
   \-~->
   (pd x0 x1))
  ((("00000-000001-000003-bowl" "person move bowl into sink")
     ("00000-000020-000003-squash" "person move squash into sink")
     ("00000-000044-000003-cabbage" "person move cabbage into sink")
     ("00000-000051-000003-cleaner" "person move cleaner into sink")
     ("00000-000146-000003-coffee" "person move coffee into sink"))
    (X0 MOVE X1 INTO SINK)
    \-~->
    (pd x0 x1))
  ((("00000-000012-000003-cabbage" "person take cabbage out of sink")
     ("00000-000015-000003-bowl" "person take bowl out of sink")
     ("00000-000038-000003-pineapple" "person take pineapple out of sink")
     ("00000-000113-000003-cleaner" "person take cleaner out of sink")
     ("00000-000358-000004-coffee" "person take coffee out of sink"))
    (X0 TAKE X1 OUT OF SINK)
    \-~->
    (pk x0 x1))
  ((("00000-000012-000003-cabbage" "person move cabbage out of bowl in sink"))
    (X0 MOVE X1 OUT OF X2 IN SINK)
    \-~->
    (pk x0 x1 i1 x1 x2))
  ((("00000-000012-000003-cabbage" "person take cabbage from bowl")
     ("00000-000204-000002-cleaner" "person take cleaner from bowl")
     ("00000-000204-000002-cleaner" "person take cleaner from bowl")
     ("00002-000041-000002-squash" "person take squash from bowl"))
    (X0 TAKE X1 FROM X2)
    \-~->
    (i1 x1 x2 aw x1 x2))
  ((("00000-000015-000003-bowl" "person move bowl out of sink")
     ("00000-000038-000003-pineapple" "person move pineapple out of sink")
     ("00000-000113-000003-cleaner" "person move cleaner out of sink"))
    (X0 MOVE X1 OUT OF SINK)
    \-~->
    (pk x0 x1))
  ((("00000-000015-000003-bowl" "person take bowl from sink")
     ("00000-000038-000003-pineapple" "person take pineapple from sink")
     ("00000-000113-000003-cleaner" "person take cleaner from sink")
     ("00000-000236-000002-pineapple" "person take pineapple from sink")
     ("00000-000319-000004-coffee" "person take coffee from sink"))
    (X0 TAKE X1 FROM SINK)
    \-~->
    (pk x0 x1))
  ((("00000-000109-000004-coffee" "person put coffee into sink")
     ("00000-000315-000004-coffee" "person put coffee into sink"))
    (X0 PUT X1 INTO SINK)
    \-~->
    (pd x0 x1))
  ((("00000-000156-000003-pineapple"
      "person put pineapple above bowl into bowl"))
    (X0 PUT X1 ABOVE X2 INTO X3)
    \-~->
    (pd x0 x1 i2 x1 x2))
  ((("00000-000156-000003-pineapple"
      "person pick pineapple up off counter put it down in bowl in sink"))
    (X0 PICK X1 UP OFF COUNTER PUT IT DOWN IN X2 IN SINK)
    \-~->
    (pd x0 x1 i2 x1 x2))
  ((("00000-000156-000003-pineapple" "person put pineapple in bowl")
     ("00000-000409-000003-cleaner" "person put cleaner in bowl")
     ("00000-000415-000002-pineapple" "person put pineapple in bowl")
     ("00000-000421-000002-cabbage" "person put cabbage in bowl")
     ("00002-000037-000003-squash" "person put squash in bowl")
     ("00002-000037-000003-squash" "person put squash in bowl")
     ("00002-000056-000002-pineapple" "person put pineapple in bowl")
     ("00002-000056-000002-pineapple" "person put pineapple in bowl")
     ("00002-000120-000002-cabbage" "person put cabbage in bowl")
     ("00002-000143-000002-cabbage" "person put cabbage in bowl")
     ("00002-000143-000002-cabbage" "person put cabbage in bowl")
     ("00002-000154-000002-pineapple" "person put pineapple in bowl"))
    (X0 PUT X1 IN X2)
    \-~->
    (mv x0 x1 tw x1 x2 i2 x1 x2))
  ((("00000-000204-000002-cleaner"
      "person pick cleaner up out of bowl put it down on counter"))
    (X0 PICK X1 UP OUT OF X2 PUT IT DOWN ON COUNTER)
    \-~->
    (pk x0 x1 i1 x1 x2))
  ((("00000-000210-000003-pineapple"
      "person put pineapple into sink move squash cabbage"))
    (X0 PUT X1 INTO SINK MOVE X2 X3)
    \-~->
    (pd x0 x1))
  ((("00000-000210-000003-pineapple"
      "person put pineapple down in sink move squash across counter"))
    (X0 PUT X1 DOWN IN SINK MOVE X2 ACROSS COUNTER)
    \-~->
    (pd x0 x1))
  ((("00000-000236-000002-pineapple"
      "person move pineapple from sink to counter")
     ("00000-000304-000003-squash" "person move squash from sink to counter")
     ("00000-000319-000004-coffee" "person move coffee from sink to counter")
     ("00000-000358-000004-coffee" "person move coffee from sink to counter")
     ("00001-000000-000003-bowl" "person move bowl from sink to counter")
     ("00001-000004-000003-cleaner" "person move cleaner from sink to counter"))
    (X0 MOVE X1 FROM SINK TO COUNTER)
    \-~->
    (pk x0 x1))
  ((("00000-000236-000002-pineapple"
      "person pick pineapple up out of sink put it rightwards on counter"))
    (X0 PICK X1 UP OUT OF SINK PUT IT RIGHTWARDS ON COUNTER)
    \-~->
    (pk x0 x1))
  ((("00000-000304-000003-squash"
      "person pick up squash out of sink put it on counter")
     ("00000-000319-000004-coffee"
       "person pick up coffee out of sink put it on counter"))
    (X0 PICK UP X1 OUT OF SINK PUT IT ON COUNTER)
    \-~->
    (pk x0 x1))
  ((("00000-000304-000003-squash" "person move squash from sink"))
    (X0 MOVE X1 FROM SINK)
    \-~->
    (pk x0 x1))
  ((("00000-000315-000004-coffee" "person stack coffee in sink"))
    (X0 STACK X1 IN SINK)
    \-~->
    (pd x0 x1))
  ((("00000-000332-000003-pineapple"
      "person move pineapple from counter to sink")
     ("00000-000341-000004-squash" "person move squash from counter to sink")
     ("00000-000354-000003-coffee" "person move coffee from counter to sink"))
    (X0 MOVE X1 FROM COUNTER TO SINK)
    \-~->
    (pd x0 x1))
  ((("00000-000332-000003-pineapple"
      "person pick up pineapple up move it to sink"))
    (X0 PICK UP X1 UP MOVE IT TO SINK)
    \-~->
    (pk x0 x1))
  ((("00000-000341-000004-squash"
      "person pick up cabbage off counter stack it in sink"))
    (X0 PICK UP X1 OFF COUNTER STACK IT IN SINK)
    \-~->
    (pd x0 x1))
  ((("00000-000354-000003-coffee"
      "person pick up coffee across counter stack it in sink"))
    (X0 PICK UP X1 ACROSS COUNTER STACK IT IN SINK)
    \-~->
    (pd x0 x1))
  ((("00000-000358-000004-coffee" "person take coffee out of sink on counter"))
    (X0 TAKE X1 OUT OF SINK ON COUNTER)
    \-~->
    (pk x0 x1))
  ((("00000-000409-000003-cleaner"
      "person move cleaner from counter to bowl in sink")
     ("00000-000415-000002-pineapple"
       "person move pineapple from counter to bowl in sink")
     ("00000-000421-000002-cabbage"
       "person move cabbage from counter to bowl in sink"))
    (X0 MOVE X1 FROM COUNTER TO X2 IN SINK)
    \-~->
    (pd x0 x1 i2 x1 x2))
  ((("00000-000409-000003-cleaner"
      "person take cleaner out of bowl put near coffee"))
    (X0 TAKE X1 OUT OF X2 PUT NEAR X3)
    \-~->
    (pk x0 x1 i1 x1 x2 n2 x1 x3))
  ((("00000-000411-000003-cleaner"
      "person move cleaner from bowl in sink near pineapple on counter"))
    (X0 MOVE X1 FROM X2 IN SINK NEAR X3 ON COUNTER)
    \-~->
    (pk x0 x1 i1 x1 x2))
  ((("00000-000411-000003-cleaner"
      "person take cleaner out of bowl put it on counter")
     ("00000-000423-000002-cabbage"
       "person take cabbage out of bowl put it on counter")
     ("00000-000423-000002-cabbage"
       "person take cabbage out of bowl put it on counter"))
    (X0 TAKE X1 OUT OF X2 PUT IT ON COUNTER)
    \-~->
    (pk x0 x1 i1 x1 x2))
  ((("00000-000411-000003-cleaner"
      "person take cleaner put it to right of pineapple"))
    (X0 TAKE X1 PUT IT TO RIGHT OF X2)
    \-~->
    (pk x0 x1))
  ((("00000-000415-000002-pineapple" "person take pineapple put it in bowl"))
    (X0 TAKE X1 PUT IT IN X2)
    \-~->
    (pd x0 x1 i2 x1 x2))
  ((("00000-000421-000002-cabbage" "person take cabbage put it in sink"))
    (X0 TAKE X1 PUT IT IN SINK)
    \-~->
    (pd x0 x1))
  ((("00000-000423-000002-cabbage"
      "person move cabbage from bowl in sink to counter"))
    (X0 MOVE X1 FROM X2 IN SINK TO COUNTER)
    \-~->
    (pk x0 x1 i1 x1 x2))
  ((("00001-000000-000003-bowl" "person move bowl from right to left")
     ("00001-000004-000003-cleaner" "person move cleaner from right to left")
     ("00001-000009-000003-pineapple"
       "person move pineapple from right to left")
     ("00001-000155-000004-squash" "person move squash from right to left")
     ("00001-000223-000002-coffee" "person move coffee from right to left")
     ("00001-000437-000003-coffee" "person move coffee from right to left")
     ("00001-000442-000002-pineapple"
       "person move pineapple from right to left"))
    (X0 MOVE X1 FROM RIGHT TO LEFT)
    \-~->
    (c x0 x1))
  ((("00001-000000-000003-bowl" "person take bowl move it to counter on left")
     ("00001-000004-000003-cleaner"
       "person take cleaner move it to counter on left")
     ("00001-000009-000003-pineapple"
       "person take pineapple move it to counter on left"))
    (X0 TAKE X1 MOVE IT TO COUNTER ON LEFT)
    \-~->
    (c x0 x1))
  ((("00001-000009-000003-pineapple"
      "person take pineapple of sink put it on counter"))
    (X0 TAKE X1 OF SINK PUT IT ON COUNTER)
    \-~->
    (pk x0 x1))
  ((("00001-000014-000003-pineapple" "person move pineapple from left to right")
     ("00001-000408-000003-coffee" "person move coffee from left to right")
     ("00001-000426-000002-squash" "person move squash from left to right")
     ("00001-000509-000003-cleaner" "person move cleaner from left to right"))
    (X0 MOVE X1 FROM LEFT TO RIGHT)
    \-~->
    (c x0 x1))
  ((("00001-000014-000003-pineapple"
      "person take pineapple off counter put it on sink"))
    (X0 TAKE X1 OFF COUNTER PUT IT ON SINK)
    \-~->
    (pd x0 x1))
  ((("00001-000014-000003-pineapple"
      "person take pineapple move it to counter on right"))
    (X0 TAKE X1 MOVE IT TO COUNTER ON RIGHT)
    \-~->
    (c x0 x1))
  ((("00001-000018-000002-cleaner" "person move cleaner rightwards")
     ("00001-000024-000003-cabbage" "person move cabbage rightwards")
     ("00001-000031-000003-coffee" "person move coffee rightwards")
     ("00001-000043-000003-bowl" "person move bowl rightwards")
     ("00001-000053-000004-squash" "person move squash rightwards")
     ("00001-000141-000004-squash" "person move squash rightwards")
     ("00001-000150-000002-bowl" "person move bowl rightwards")
     ("00001-000348-000002-bowl" "person move bowl rightwards")
     ("00001-000408-000003-coffee" "person move coffee rightwards")
     ("00001-000426-000002-squash" "person move squash rightwards")
     ("00001-000509-000003-cleaner" "person move cleaner rightwards"))
    (X0 MOVE X1 RIGHTWARDS)
    \-~->
    (c x0 x1))
  ((("00001-000018-000002-cleaner" "person carry cleaner rightwards")
     ("00001-000018-000002-cleaner" "person carry cleaner rightwards")
     ("00001-000024-000003-cabbage" "person carry cabbage rightwards")
     ("00001-000031-000003-coffee" "person carry coffee rightwards")
     ("00001-000031-000003-coffee" "person carry coffee rightwards")
     ("00001-000043-000003-bowl" "person carry bowl rightwards")
     ("00001-000053-000004-squash" "person carry squash rightwards")
     ("00001-000141-000004-squash" "person carry squash rightwards")
     ("00005-000204-000002-cooler" "person carry cooler rightwards")
     ("00005-000204-000002-cooler" "person carry cooler rightwards")
     ("00008-000514-000002-watering-pot" "person carry watering-pot rightwards")
     ("00008-000528-000002-bucket" "person carry bucket rightwards"))
    (X0 CARRY X1 RIGHTWARDS)
    \-~->
    (c x0 x1))
  ((("00001-000024-000003-cabbage" "person put cabbage near cleaner")
     ("00001-000043-000003-bowl" "person put bowl near cabbage")
     ("00001-000141-000004-squash" "person put squash near cabbage")
     ("00004-000520-000003-cooler" "person put cooler near box")
     ("00008-000109-000002-gas-can" "person put gas-can near bucket")
     ("00008-000218-000002-gas-can" "person put gas-can near bucket")
     ("00008-000325-000003-gas-can" "person put gas-can near bucket")
     ("00008-000325-000003-gas-can" "person put gas-can near bucket"))
    (X0 PUT X1 NEAR X2)
    \-~->
    (mv x0 x1 n2 x1 x2))
  ((("00001-000053-000004-squash"
      "person carry squash rightwards put it near bowl")
     ("00001-000150-000002-bowl"
       "person carry bowl rightwards put it near squash")
     ("00001-000150-000002-bowl"
       "person carry bowl rightwards put it near squash"))
    (X0 CARRY X1 RIGHTWARDS PUT IT NEAR X2)
    \-~->
    (c x0 x1 n2 x1 x2))
  ((("00001-000059-000003-squash" "person move squash leftwards")
     ("00001-000132-000003-bowl" "person move bowl leftwards")
     ("00001-000136-000003-coffee" "person move coffee leftwards")
     ("00001-000400-000003-pineapple" "person move pineapple leftwards")
     ("00001-000437-000003-coffee" "person move coffee leftwards")
     ("00001-000442-000002-pineapple" "person move pineapple leftwards")
     ("00001-000507-000002-cleaner" "person move cleaner leftwards"))
    (X0 MOVE X1 LEFTWARDS)
    \-~->
    (c x0 x1))
  ((("00001-000059-000003-squash" "person carry squash leftwards")
     ("00001-000059-000003-squash" "person carry squash leftwards")
     ("00001-000136-000003-coffee" "person carry coffee leftwards")
     ("00004-000320-000004-box" "person carry box leftwards")
     ("00004-000508-000003-box" "person carry box leftwards")
     ("00008-000524-000002-bucket" "person carry bucket leftwards"))
    (X0 CARRY X1 LEFTWARDS)
    \-~->
    (c x0 x1))
  ((("00001-000132-000003-bowl"
      "person carry bowl leftwards put it near squash")
     ("00001-000136-000003-coffee"
       "person carry coffee leftwards put it near bowl"))
    (X0 CARRY X1 LEFTWARDS PUT IT NEAR X2)
    \-~->
    (c x0 x1 n2 x1 x2))
  ((("00001-000132-000003-bowl" "person put bowl to right of squash")
     ("00004-000520-000003-cooler" "person put cooler to right of box")
     ("00008-000113-000004-watering-pot"
       "person put watering-pot to right of bucket")
     ("00008-000340-000002-bucket" "person put bucket to right of gas-can")
     ("00008-000640-000003-bucket" "person put bucket to right of gas-can")
     ("00008-000644-000002-watering-pot"
       "person put watering-pot to right of bucket"))
    (X0 PUT X1 TO RIGHT OF X2)
    \-~->
    (mv x0 x1 r2 x1 x2))
  ((("00001-000155-000004-squash"
      "person move squash to counter put it between coffee cabbage"))
    (X0 MOVE X1 TO COUNTER PUT IT BETWEEN X2 X3)
    \-~->
    (c x0 x1))
  ((("00001-000155-000004-squash" "person move squash to counter")
     ("00001-000159-000003-pineapple" "person move pineapple to counter")
     ("00001-000213-000002-pineapple" "person move pineapple to counter")
     ("00001-000219-000002-squash" "person move squash to counter")
     ("00001-000223-000002-coffee" "person move coffee to counter")
     ("00001-000233-000002-pineapple" "person move pineapple to counter")
     ("00001-000238-000002-squash" "person move squash to counter")
     ("00001-000256-000003-pineapple" "person move pineapple to counter"))
    (X0 MOVE X1 TO COUNTER)
    \-~->
    (c x0 x1))
  ((("00001-000159-000003-pineapple"
      "person move coffee put pineapple in put of it"))
    (X0 MOVE X1 PUT X2 IN PUT OF IT)
    \-~->
    (c x0 x2))
  ((("00001-000159-000003-pineapple"
      "person move coffee move pineapple from right to left"))
    (X0 MOVE X1 MOVE X2 FROM RIGHT TO LEFT)
    \-~->
    (c x0 x2))
  ((("00001-000213-000002-pineapple"
      "person move pineapple put it between squash bowl"))
    (X0 MOVE X1 PUT IT BETWEEN X2 X3)
    \-~->
    (c x0 x1))
  ((("00001-000213-000002-pineapple"
      "person carry pineapple to right near bowl"))
    (X0 CARRY X1 TO RIGHT NEAR X2)
    \-~->
    (c x0 x1 n2 x1 x2))
  ((("00001-000219-000002-squash" "person carry squash from left to right")
     ("00008-000514-000002-watering-pot"
       "person carry watering-pot from left to right")
     ("00008-000524-000002-bucket" "person carry bucket from left to right"))
    (X0 CARRY X1 FROM LEFT TO RIGHT)
    \-~->
    (c x0 x1))
  ((("00001-000219-000002-squash" "person carry squash to left near cabbage")
     ("00001-000233-000002-pineapple"
       "person carry pineapple to left near squash"))
    (X0 CARRY X1 TO LEFT NEAR X2)
    \-~->
    (c x0 x1 n2 x1 x2))
  ((("00001-000223-000002-coffee" "person put coffee on right near pineapple")
     ("00001-000348-000002-bowl" "person put bowl on right near cleaner")
     ("00001-000408-000003-coffee" "person put coffee on right near bowl")
     ("00001-000426-000002-squash" "person put squash on right near bowl")
     ("00001-000509-000003-cleaner"
       "person put cleaner on right near pineapple"))
    (X0 PUT X1 ON RIGHT NEAR X2)
    \-~->
    (c x0 x1 n2 x1 x2))
  ((("00001-000227-000003-cabbage"
      "person move cabbage from right put it in left"))
    (X0 MOVE X1 FROM RIGHT PUT IT IN LEFT)
    \-~->
    (c x0 x1))
  ((("00001-000227-000003-cabbage"
      "person move cabbage from left to right near coffee")
     ("00001-000238-000002-squash"
       "person move squash from left to right near coffee"))
    (X0 MOVE X1 FROM LEFT TO RIGHT NEAR X2)
    \-~->
    (c x0 x1 n2 x1 x2))
  ((("00001-000227-000003-cabbage" "person put cabbage on counter"))
    (X0 PUT X1 ON COUNTER)
    \-~->
    (c x0 x1))
  ((("00001-000233-000002-pineapple"
      "person pick up pineapple put it near squash which on top of right"))
    (X0 PICK UP X1 PUT IT NEAR X2 WHICH ON TOP OF RIGHT)
    \-~->
    (c x0 x1 n2 x1 x2))
  ((("00001-000238-000002-squash"
      "person carry squash to left put it near coffee"))
    (X0 CARRY X1 TO LEFT PUT IT NEAR X2)
    \-~->
    (c x0 x1 n2 x1 x2))
  ((("00001-000256-000003-pineapple"
      "person pick up pineapple from right carry it to left"))
    (X0 PICK UP X1 FROM RIGHT CARRY IT TO LEFT)
    \-~->
    (c x0 x1))
  ((("00001-000256-000003-pineapple"
      "person move pineapple near cabbage to left near squash"))
    (X0 MOVE X1 NEAR X2 TO LEFT NEAR X3)
    \-~->
    (c x0 x1 n1 x1 x2 n2 x1 x3))
  ((("00001-000317-000002-bowl" "person carry bowl to right")
     ("00005-000403-000002-box" "person carry box to right")
     ("00006-000049-000002-cooler" "person carry cooler to right"))
    (X0 CARRY X1 TO RIGHT)
    \-~->
    (c x0 x1))
  ((("00001-000317-000002-bowl"
      "person carry bowl near pineapple to left near coffee"))
    (X0 CARRY X1 NEAR X2 TO LEFT NEAR X3)
    \-~->
    (c x0 x1 n1 x1 x2 n2 x1 x3))
  ((("00001-000317-000002-bowl" "person move bowl to counter near sink"))
    (X0 MOVE X1 TO COUNTER NEAR SINK)
    \-~->
    (c x0 x1))
  ((("00001-000348-000002-bowl" "person put bowl on left to right"))
    (X0 PUT X1 ON LEFT TO RIGHT)
    \-~->
    (c x0 x1))
  ((("00001-000400-000003-pineapple" "person put pineapple on right to left"))
    (X0 PUT X1 ON RIGHT TO LEFT)
    \-~->
    (c x0 x1))
  ((("00001-000400-000003-pineapple" "person put pineapple on left near coffee")
     ("00001-000442-000002-pineapple"
       "person put pineapple on left near coffee")
     ("00001-000507-000002-cleaner" "person put cleaner on left near coffee"))
    (X0 PUT X1 ON LEFT NEAR X2)
    \-~->
    (c x0 x1 n2 x1 x2))
  ((("00001-000437-000003-coffee" "person put coffee on left"))
    (X0 PUT X1 ON LEFT)
    \-~->
    (c x0 x1))
  ((("00001-000507-000002-cleaner" "person carry cleaner from right to left")
     ("00008-000528-000002-bucket" "person carry bucket from right to left"))
    (X0 CARRY X1 FROM RIGHT TO LEFT)
    \-~->
    (c x0 x1))
  ((("00002-000006-000003-cabbage" "person move cabbage out of bowl"))
    (X0 MOVE X1 OUT OF X2)
    \-~->
    (mv x0 x1 i1 x1 x2 aw x1 x2))
  ((("00002-000006-000003-cabbage"
      "person take cabbage out of bowl put it to right"))
    (X0 TAKE X1 OUT OF X2 PUT IT TO RIGHT)
    \-~->
    (mv x0 x1 i1 x1 x2 aw x1 x2))
  ((("00002-000006-000003-cabbage" "person take cabbage out of bowl")
     ("00002-000041-000002-squash" "person take squash out of bowl")
     ("00002-000041-000002-squash" "person take squash out of bowl")
     ("00002-000058-000002-pineapple" "person take pineapple out of bowl")
     ("00002-000058-000002-pineapple" "person take pineapple out of bowl")
     ("00002-000112-000002-squash" "person take squash out of bowl")
     ("00002-000112-000002-squash" "person take squash out of bowl")
     ("00002-000123-000002-cabbage" "person take cabbage out of bowl")
     ("00002-000123-000002-cabbage" "person take cabbage out of bowl")
     ("00002-000147-000002-cabbage" "person take cabbage out of bowl")
     ("00002-000147-000002-cabbage" "person take cabbage out of bowl"))
    (X0 TAKE X1 OUT OF X2)
    \-~->
    (mv x0 x1 i1 x1 x2 aw x1 x2))
  ((("00002-000016-000005-pineapple" "person move pineapple into bowl"))
    (X0 MOVE X1 INTO X2)
    \-~->
    (mv x0 x1 tw x1 x2 i2 x1 x2))
  ((("00002-000016-000005-pineapple"
      "person put pineapple to right of bowl into bowl"))
    (X0 PUT X1 TO RIGHT OF X2 INTO X3)
    \-~->
    (mv x0 x1 tw x1 x2 i2 x1 x2))
  ((("00002-000016-000005-pineapple" "person put pineapple into bowl")
     ("00002-000037-000003-squash" "person put squash into bowl")
     ("00002-000120-000002-cabbage" "person put cabbage into bowl")
     ("00002-000143-000002-cabbage" "person put cabbage into bowl")
     ("00002-000154-000002-pineapple" "person put pineapple into bowl"))
    (X0 PUT X1 INTO X2)
    \-~->
    (mv x0 x1 tw x1 x2 i2 x1 x2))
  ((("00002-000058-000002-pineapple"
      "person take pineapple from sink put it on counter")
     ("00002-000123-000002-cabbage"
       "person take cabbage from sink put it on counter"))
    (X0 TAKE X1 FROM SINK PUT IT ON COUNTER)
    \-~->
    (pk x0 x1))
  ((("00002-000112-000002-squash"
      "person take pineapple from bowl put it on counter")
     ("00002-000147-000002-cabbage"
       "person take cabbage from bowl put it on counter"))
    (X0 TAKE X1 FROM X2 PUT IT ON COUNTER)
    \-~->
    (mv x0 x1 i1 x1 x2 aw x1 x2))
  ((("00003-000002-000003-ketchup" "person pour ketchup into cup")
     ("00003-000014-000004-milk" "person pour milk into cup")
     ("00003-000036-000004-juice" "person pour juice into cup")
     ("00003-000036-000004-juice" "person pour juice into cup")
     ("00003-000059-000004-juice" "person pour juice into cup")
     ("00003-000107-000003-milk" "person pour milk into cup")
     ("00003-000118-000004-ketchup" "person pour ketchup into cup")
     ("00003-000118-000004-ketchup" "person pour ketchup into cup")
     ("00003-000143-000003-ketchup" "person pour ketchup into cup")
     ("00003-000153-000003-milk" "person pour milk into cup")
     ("00003-000245-000004-ketchup" "person pour ketchup into cup")
     ("00003-000306-000004-juice" "person pour juice into cup")
     ("00003-000336-000004-milk" "person pour milk into cup")
     ("00003-000350-000004-juice" "person pour juice into cup")
     ("00003-000600-000004-juice" "person pour juice into cup")
     ("00003-000600-000004-juice" "person pour juice into cup"))
    (X0 POUR X1 INTO X2)
    \-~->
    (rt x0 x1 aa x1 x2))
  ((("00003-000002-000003-ketchup" "person pour ketchup into cup on right")
     ("00003-000107-000003-milk" "person pour milk into cup on right")
     ("00003-000143-000003-ketchup" "person pour ketchup into cup on right")
     ("00003-000153-000003-milk" "person pour milk into cup on right")
     ("00003-000245-000004-ketchup" "person pour ketchup into cup on right")
     ("00003-000306-000004-juice" "person pour juice into cup on right")
     ("00003-000540-000003-milk" "person pour milk into cup on right"))
    (X0 POUR X1 INTO X2 ON RIGHT)
    \-~->
    (rt x0 x1 aa x1 x2))
  ((("00003-000002-000003-ketchup" "person pour ketchup in cup"))
    (X0 POUR X1 IN X2)
    \-~->
    (rt x0 x1 aa x1 x2))
  ((("00003-000014-000004-milk" "person pour milk near ketchup"))
    (X0 POUR X1 NEAR X2)
    \-~->
    (rt x0 x1 n1 x1 x2))
  ((("00003-000014-000004-milk" "person move cup pour milk")
     ("00003-000036-000004-juice" "person move cup pour juice"))
    (X0 MOVE X1 POUR X2)
    \-~->
    (rt x0 x2 aa x2 x1))
  ((("00003-000059-000004-juice" "person pour juice")
     ("00003-000107-000003-milk" "person pour milk"))
    (X0 POUR X1)
    \-~->
    (rt x0 x1))
  ((("00003-000059-000004-juice" "person move pour juice into cup"))
    (X0 MOVE POUR X1 INTO X2)
    \-~->
    (rt x0 x1 aa x1 x2))
  ((("00003-000118-000004-ketchup" "person pour ketchup near juice milk"))
    (X0 POUR X1 NEAR X2 X3)
    \-~->
    (rt x0 x1 n1 x1 x2 n1 x1 x3))
  ((("00003-000143-000003-ketchup" "person pour ketchup into left cup")
     ("00003-000153-000003-milk" "person pour milk into left cup"))
    (X0 POUR X1 INTO LEFT X2)
    \-~->
    (rt x0 x1 aa x1 x2))
  ((("00003-000245-000004-ketchup"
      "person hold ketchup pour it into cup on left")
     ("00003-000306-000004-juice" "person hold juice pour it into cup on left"))
    (X0 HOLD X1 POUR IT INTO X2 ON LEFT)
    \-~->
    (rt x0 x1 aa x1 x2))
  ((("00003-000336-000004-milk" "person add milk to cup")
     ("00003-000346-000003-ketchup" "person add juice to cup")
     ("00003-000346-000003-ketchup" "person add ketchup to cup")
     ("00003-000350-000004-juice" "person add juice to cup")
     ("00003-000418-000004-ketchup" "person add juice to cup")
     ("00003-000424-000003-juice" "person add juice to cup"))
    (X0 ADD X1 TO X2)
    \-~->
    (rt x0 x1 aa x1 x2))
  ((("00003-000336-000004-milk" "person pick up milk pour")
     ("00003-000346-000003-ketchup" "person pick up ketchup pour")
     ("00003-000350-000004-juice" "person pick up juice pour")
     ("00003-000418-000004-ketchup" "person pick up ketchup pour"))
    (X0 PICK UP X1 POUR)
    \-~->
    (rt x0 x1))
  ((("00003-000418-000004-ketchup" "person pour ketchup into cup near juice")
     ("00003-000424-000003-juice" "person pour juice into cup near ketchup")
     ("00003-000518-000004-juice" "person pour juice into cup near cup"))
    (X0 POUR X1 INTO X2 NEAR X3)
    \-~->
    (rt x0 x1 aa x1 x2 n1 x2 x3))
  ((("00003-000424-000003-juice" "person pick up juice pour it")
     ("00003-000518-000004-juice" "person pick up juice pour it"))
    (X0 PICK UP X1 POUR IT)
    \-~->
    (rt x0 x1))
  ((("00003-000459-000004-ketchup" "person add juice to cup on left")
     ("00003-000508-000005-milk" "person add milk to cup on left"))
    (X0 ADD X1 TO X2 ON LEFT)
    \-~->
    (rt x0 x1 aa x1 x2))
  ((("00003-000459-000004-ketchup" "person pour ketchup into cup on left")
     ("00003-000508-000005-milk" "person pour milk into cup on left")
     ("00003-000600-000004-juice" "person pour juice into cup on left"))
    (X0 POUR X1 INTO X2 ON LEFT)
    \-~->
    (rt x0 x1 aa x1 x2))
  ((("00003-000459-000004-ketchup"
      "person pick up ketchup pour it into right cup")
     ("00003-000508-000005-milk" "person pick up milk pour it into right cup"))
    (X0 PICK UP X1 POUR IT INTO RIGHT X2)
    \-~->
    (rt x0 x1 aa x1 x2))
  ((("00003-000518-000004-juice" "person add juice to cup in front"))
    (X0 ADD X1 TO X2 IN FRONT)
    \-~->
    (rt x0 x1 aa x1 x2))
  ((("00003-000540-000003-milk" "person add milk to cup on right")
     ("00003-000548-000002-ketchup" "person add juice to cup on right"))
    (X0 ADD X1 TO X2 ON RIGHT)
    \-~->
    (rt x0 x1 aa x1 x2))
  ((("00003-000540-000003-milk" "person pick up milk pour into left cup")
     ("00003-000548-000002-ketchup" "person pick up ketchup pour into left cup"))
    (X0 PICK UP X1 POUR INTO LEFT X2)
    \-~->
    (rt x0 x1 aa x1 x2))
  ((("00003-000548-000002-ketchup"
      "person pour ketchup into cup to right of cup"))
    (X0 POUR X1 INTO X2 TO RIGHT OF X3)
    \-~->
    (rt x0 x1 aa x1 x2 r x2 x3))
  ((("00004-000006-000003-cooler" "person put cooler on table")
     ("00004-000006-000003-cooler" "person put cooler on table")
     ("00004-000028-000003-cooler" "person put cooler on table")
     ("00004-000028-000003-cooler" "person put cooler on table")
     ("00004-000035-000003-box" "person put box on table")
     ("00004-000035-000003-box" "person put box on table")
     ("00004-000158-000004-cooler" "person put cooler on table")
     ("00004-000508-000003-box" "person put box on table")
     ("00004-000508-000003-box" "person put box on table")
     ("00005-000029-000002-box" "person put box on table")
     ("00005-000100-000002-cooler" "person put cooler on table")
     ("00005-000252-000002-cooler" "person put cooler on table")
     ("00005-000255-000002-box" "person put box on table")
     ("00005-000614-000003-cooler" "person put cooler on table")
     ("00005-000614-000003-cooler" "person put cooler on table"))
    (X0 PUT X1 ON TABLE)
    \-~->
    (vr x0 x1))
  ((("00004-000006-000003-cooler" "person pick up cooler up on table"))
    (X0 PICK UP X1 UP ON TABLE)
    \-~->
    (pk x0 x1))
  ((("00004-000012-000002-cooler" "person put cooler on ground")
     ("00004-000040-000002-box" "person put box on ground")
     ("00004-000104-000002-cooler" "person put cooler on ground")
     ("00004-000457-000002-box" "person put box on ground")
     ("00005-000001-000003-cooler" "person put cooler on ground")
     ("00005-000001-000003-cooler" "person put cooler on ground")
     ("00005-000214-000002-box" "person put box on ground")
     ("00005-000214-000002-box" "person put box on ground")
     ("00008-000105-000002-bucket" "person put bucket on ground")
     ("00008-000109-000002-gas-can" "person put gas-can on ground")
     ("00008-000109-000002-gas-can" "person put gas-can on ground")
     ("00008-000113-000004-watering-pot" "person put watering-pot on ground")
     ("00008-000218-000002-gas-can" "person put gas-can on ground")
     ("00008-000337-000002-gas-can" "person put gas-can on ground")
     ("00008-000337-000002-gas-can" "person put gas-can on ground"))
    (X0 PUT X1 ON GROUND)
    \-~->
    (pd x0 x1))
  ((("00004-000012-000002-cooler" "person take cooler off table")
     ("00004-000040-000002-box" "person take box off table")
     ("00004-000104-000002-cooler" "person take cooler off table"))
    (X0 TAKE X1 OFF TABLE)
    \-~->
    (pd x0 x1))
  ((("00004-000012-000002-cooler"
      "person pick up cooler from table put it down"))
    (X0 PICK UP X1 FROM TABLE PUT IT DOWN)
    \-~->
    (pd x0 x1))
  ((("00004-000028-000003-cooler"
      "person pick cooler up from down put it on top"))
    (X0 PICK X1 UP FROM DOWN PUT IT ON TOP)
    \-~->
    (pk x0 x1))
  ((("00004-000035-000003-box" "person pick up box put it on top of table"))
    (X0 PICK UP X1 PUT IT ON TOP OF TABLE)
    \-~->
    (pk x0 x1))
  ((("00004-000040-000002-box" "person pick up box put it down")
     ("00004-000104-000002-cooler" "person pick up cooler put it down"))
    (X0 PICK UP X1 PUT IT DOWN)
    \-~->
    (pd x0 x1))
  ((("00004-000156-000002-cooler" "person put cooler on top of cooler")
     ("00004-000156-000002-cooler" "person put cooler on top of cooler")
     ("00004-000529-000002-cooler" "person put cooler on top of box")
     ("00004-000529-000002-cooler" "person put cooler on top of box")
     ("00005-000004-000003-box" "person put box on top of cooler")
     ("00008-000102-000003-bucket" "person put bucket on top of box"))
    (X0 PUT X1 ON TOP OF X2)
    \-~->
    (mv x0 x1 t2 x1 x2))
  ((("00004-000156-000002-cooler" "person stack cooler on cooler"))
    (X0 STACK X1 ON X2)
    \-~->
    (mv x0 x1 t2 x1 x2))
  ((("00004-000158-000004-cooler" "person move cooler to table"))
    (X0 MOVE X1 TO TABLE)
    \-~->
    (mv x0 x1))
  ((("00004-000158-000004-cooler" "person take cooler from on top of"))
    (X0 TAKE X1 FROM ON TOP OF)
    \-~->
    (pd x0 x1))
  ((("00004-000210-000002-cooler" "person put cooler on cooler")
     ("00004-000236-000003-cooler" "person put cooler on box")
     ("00004-000529-000002-cooler" "person put cooler on box")
     ("00005-000032-000003-cooler" "person put cooler on box")
     ("00005-000306-000003-cooler" "person put cooler on cooler")
     ("00008-000158-000003-bucket" "person put bucket on box"))
    (X0 PUT X1 ON X2)
    \-~->
    (mv x0 x1 t2 x1 x2))
  ((("00004-000210-000002-cooler" "person move cooler on top of cooler"))
    (X0 MOVE X1 ON TOP OF X2)
    \-~->
    (mv x0 x1 t2 x1 x2))
  ((("00004-000210-000002-cooler" "person put cooler on to top of cooler"))
    (X0 PUT X1 ON TO TOP OF X2)
    \-~->
    (mv x0 x1 t2 x1 x2))
  ((("00004-000236-000003-cooler" "person pick up cooler on top of box"))
    (X0 PICK UP X1 ON TOP OF X2)
    \-~->
    (pk x0 x1 t2 x1 x2))
  ((("00004-000236-000003-cooler" "person pick up cooler put it on box"))
    (X0 PICK UP X1 PUT IT ON X2)
    \-~->
    (pk x0 x1 t2 x1 x2))
  ((("00004-000320-000004-box" "person carry box to right of chair"))
    (X0 CARRY X1 TO RIGHT OF CHAIR)
    \-~->
    (c x0 x1))
  ((("00004-000320-000004-box" "person carry box")
     ("00005-000403-000002-box" "person carry box")
     ("00006-000042-000002-cooler" "person carry cooler")
     ("00008-000514-000002-watering-pot" "person carry watering-pot")
     ("00008-000524-000002-bucket" "person carry bucket")
     ("00008-000528-000002-bucket" "person carry bucket"))
    (X0 CARRY X1)
    \-~->
    (c x0 x1))
  ((("00004-000438-000003-box" "person put box on top of chair")
     ("00004-000447-000003-box" "person put box on top of chair"))
    (X0 PUT X1 ON TOP OF CHAIR)
    \-~->
    (pd x0 x1))
  ((("00004-000438-000003-box" "person put box on chair")
     ("00004-000447-000003-box" "person put box on chair")
     ("00005-000339-000002-box" "person put box on chair")
     ("00005-000641-000003-cooler" "person put cooler on chair"))
    (X0 PUT X1 ON CHAIR)
    \-~->
    (pd x0 x1))
  ((("00004-000438-000003-box" "person put box on left chair"))
    (X0 PUT X1 ON LEFT CHAIR)
    \-~->
    (pd x0 x1))
  ((("00004-000447-000003-box" "person put box on right chair"))
    (X0 PUT X1 ON RIGHT CHAIR)
    \-~->
    (pd x0 x1))
  ((("00004-000450-000002-box" "person pick up box off of chair"))
    (X0 PICK UP X1 OFF OF CHAIR)
    \-~->
    (pk x0 x1))
  ((("00004-000450-000002-box" "person pick up box off chair"))
    (X0 PICK UP X1 OFF CHAIR)
    \-~->
    (pk x0 x1))
  ((("00004-000450-000002-box" "person move box from chair to table"))
    (X0 MOVE X1 FROM CHAIR TO TABLE)
    \-~->
    (pk x0 x1))
  ((("00004-000457-000002-box" "person put box to right of chair"))
    (X0 PUT X1 TO RIGHT OF CHAIR)
    \-~->
    (pd x0 x1))
  ((("00004-000457-000002-box" "person carry box leftwards put it on ground"))
    (X0 CARRY X1 LEFTWARDS PUT IT ON GROUND)
    \-~->
    (c x0 x1 pd x0 x1))
  ((("00004-000520-000003-cooler" "person put cooler near box on table")
     ("00005-000255-000002-box" "person put box near cooler on table"))
    (X0 PUT X1 NEAR X2 ON TABLE)
    \-~->
    (mv x0 x1 n2 x1 x2))
  ((("00004-000527-000002-cooler" "person pick up cooler which near box"))
    (X0 PICK UP X1 WHICH NEAR X2)
    \-~->
    (c x0 x1 n1 x1 x2))
  ((("00004-000527-000002-cooler" "person pick up cooler"))
    (X0 PICK UP X1)
    \-~->
    (pk x0 x1))
  ((("00004-000527-000002-cooler" "person take cooler off of table"))
    (X0 TAKE X1 OFF OF TABLE)
    \-~->
    (c x0 x1))
  ((("00005-000001-000003-cooler" "person put cooler down")
     ("00008-000051-000003-bucket" "person put bucket down"))
    (X0 PUT X1 DOWN)
    \-~->
    (pd x0 x1))
  ((("00005-000004-000003-box" "person put box on top of cooler on ground")
     ("00005-000306-000003-cooler"
       "person put cooler on top of cooler on ground"))
    (X0 PUT X1 ON TOP OF X2 ON GROUND)
    \-~->
    (pd x0 x1 t2 x1 x2))
  ((("00005-000004-000003-box" "person put box down on cooler"))
    (X0 PUT X1 DOWN ON X2)
    \-~->
    (pd x0 x1 t2 x1 x2))
  ((("00005-000029-000002-box" "person put box up on table"))
    (X0 PUT X1 UP ON TABLE)
    \-~->
    (pk x0 x1))
  ((("00005-000029-000002-box"
      "person pick up box from on top of cooler to table"))
    (X0 PICK UP X1 FROM ON TOP OF X2 TO TABLE)
    \-~->
    (pk x0 x1 t1 x1 x2))
  ((("00005-000032-000003-cooler" "person put cooler on top of box on table"))
    (X0 PUT X1 ON TOP OF X2 ON TABLE)
    \-~->
    (mv x0 x1 t2 x1 x2))
  ((("00005-000032-000003-cooler" "person pick up cooler on box"))
    (X0 PICK UP X1 ON X2)
    \-~->
    (pk x0 x1 t2 x1 x2))
  ((("00005-000100-000002-cooler" "person put cooler on table near box cooler"))
    (X0 PUT X1 ON TABLE NEAR X2 X3)
    \-~->
    (vr x0 x1 n2 x1 x2 n2 x1 x3))
  ((("00005-000100-000002-cooler" "person pick up cooler on table")
     ("00005-000252-000002-cooler" "person pick up cooler on table")
     ("00005-000255-000002-box" "person pick up box on table"))
    (X0 PICK UP X1 ON TABLE)
    \-~->
    (pk x0 x1))
  ((("00005-000204-000002-cooler" "person take cooler"))
    (X0 TAKE X1)
    \-~->
    (mv x0 x1))
  ((("00005-000214-000002-box" "person put box on ground down"))
    (X0 PUT X1 ON GROUND DOWN)
    \-~->
    (pd x0 x1))
  ((("00005-000252-000002-cooler" "person put cooler on top of table"))
    (X0 PUT X1 ON TOP OF TABLE)
    \-~->
    (vr x0 x1))
  ((("00005-000306-000003-cooler" "person lower cooler on top of cooler"))
    (X0 LOWER X1 ON TOP OF X2)
    \-~->
    (pd x0 x1 t2 x1 x2))
  ((("00005-000339-000002-box" "person pick box off chair put it on chair"))
    (X0 PICK X1 OFF CHAIR PUT IT ON CHAIR)
    \-~->
    (pd x0 x1))
  ((("00005-000339-000002-box" "person move box to chair below"))
    (X0 MOVE X1 TO CHAIR BELOW)
    \-~->
    (pd x0 x1))
  ((("00005-000403-000002-box" "person pick up box walk"))
    (X0 PICK UP X1 WALK)
    \-~->
    (mv x0 x1))
  ((("00005-000614-000003-cooler"
      "person pick up cooler off cooler put it on table"))
    (X0 PICK UP X1 OFF X2 PUT IT ON TABLE)
    \-~->
    (vr x0 x1 t1 x1 x2))
  ((("00005-000641-000003-cooler" "person pick cooler up put it on chair"))
    (X0 PICK X1 UP PUT IT ON CHAIR)
    \-~->
    (vr x0 x1))
  ((("00005-000641-000003-cooler" "person move cooler to chair"))
    (X0 MOVE X1 TO CHAIR)
    \-~->
    (mv x0 x1))
  ((("00006-000027-000003-box"
      "person pick box off cooler put it on cooler which on ground"))
    (X0 PICK X1 OFF X2 PUT IT ON X3 WHICH ON GROUND)
    \-~->
    (pd x0 x1 t1 x1 x2 t2 x1 x3))
  ((("00006-000027-000003-box" "person move box to on top of cooler"))
    (X0 MOVE X1 TO ON TOP OF X2)
    \-~->
    (mv x0 x1 t2 x1 x2))
  ((("00006-000027-000003-box"
      "person move box from cooler on table to cooler on ground"))
    (X0 MOVE X1 FROM X2 ON TABLE TO X3 ON GROUND)
    \-~->
    (pd x0 x1 t1 x1 x2 t2 x1 x3))
  ((("00006-000042-000002-cooler" "person pick up cooler put it on chair"))
    (X0 PICK UP X1 PUT IT ON CHAIR)
    \-~->
    (vr x0 x1))
  ((("00006-000042-000002-cooler" "person carry cooler to left"))
    (X0 CARRY X1 TO LEFT)
    \-~->
    (c x0 x1))
  ((("00006-000049-000002-cooler" "person carry cooler put it on ground"))
    (X0 CARRY X1 PUT IT ON GROUND)
    \-~->
    (pd x0 x1))
  ((("00006-000049-000002-cooler" "person put cooler down on ground")
     ("00008-000017-000002-watering-pot"
       "person put watering-pot down on ground"))
    (X0 PUT X1 DOWN ON GROUND)
    \-~->
    (pd x0 x1))
  ((("00008-000014-000003-watering-pot"
      "person pick up watering-pot put it in trunk of car"))
    (X0 PICK UP X1 PUT IT IN TRUNK OF CAR)
    \-~->
    (pk x0 x1))
  ((("00008-000014-000003-watering-pot" "person put watering-pot in trunk")
     ("00008-000014-000003-watering-pot" "person put watering-pot in trunk")
     ("00008-000049-000002-bucket" "person put bucket in trunk")
     ("00008-000049-000002-bucket" "person put bucket in trunk")
     ("00008-000102-000003-bucket" "person put bucket in trunk")
     ("00008-000105-000002-bucket" "person put gas-can in trunk")
     ("00008-000158-000003-bucket" "person put bucket in trunk")
     ("00008-000158-000003-bucket" "person put bucket in trunk")
     ("00008-000320-000003-bucket" "person put bucket in trunk")
     ("00008-000320-000003-bucket" "person put bucket in trunk")
     ("00008-000325-000003-gas-can" "person put gas-can in trunk"))
    (X0 PUT X1 IN TRUNK)
    \-~->
    (pk x0 x1))
  ((("00008-000017-000002-watering-pot"
      "person pick watering-pot up out of trunk put it on ground"))
    (X0 PICK X1 UP OUT OF TRUNK PUT IT ON GROUND)
    \-~->
    (pd x0 x1))
  ((("00008-000017-000002-watering-pot" "person take watering-pot out of trunk")
     ("00008-000051-000003-bucket" "person take bucket out of trunk")
     ("00008-000637-000002-gas-can" "person take gas-can out of trunk"))
    (X0 TAKE X1 OUT OF TRUNK)
    \-~->
    (pd x0 x1))
  ((("00008-000049-000002-bucket"
      "person pick bucket up off ground put it in trunk of car"))
    (X0 PICK X1 UP OFF GROUND PUT IT IN TRUNK OF CAR)
    \-~->
    (pk x0 x1))
  ((("00008-000051-000003-bucket" "person take bucket from trunk")
     ("00008-000113-000004-watering-pot" "person take watering-pot from trunk")
     ("00008-000218-000002-gas-can" "person take gas-can from trunk"))
    (X0 TAKE X1 FROM TRUNK)
    \-~->
    (pd x0 x1))
  ((("00008-000102-000003-bucket" "person put bucket on box in trunk")
     ("00008-000439-000002-watering-pot"
       "person put watering-pot on box in trunk"))
    (X0 PUT X1 ON X2 IN TRUNK)
    \-~->
    (pk x0 x1 t2 x1 x2))
  ((("00008-000105-000002-bucket" "person take bucket put in gas-can"))
    (X0 TAKE X1 PUT IN X2)
    \-~->
    (pd x0 x1 pk x0 x2))
  ((("00008-000320-000003-bucket" "person put bucket into trunk"))
    (X0 PUT X1 INTO TRUNK)
    \-~->
    (pk x0 x1))
  ((("00008-000337-000002-gas-can" "person put gas-can on ground near trunk"))
    (X0 PUT X1 ON GROUND NEAR TRUNK)
    \-~->
    (pd x0 x1))
  ((("00008-000340-000002-bucket"
      "person take bucket out of trunk put it on ground")
    ("00008-000637-000002-gas-can" "person take gas-can out of trunk put it on ground"))
    (X0 TAKE X1 OUT OF TRUNK PUT IT ON GROUND)
    \-~->
    (pd x0 x1))
  ((("00008-000340-000002-bucket" "person unload bucket from trunk"))
    (X0 UNLOAD X1 FROM TRUNK)
    \-~->
    (pd x0 x1))
  ((("00008-000439-000002-watering-pot"
      "person load watering-pot on top of box"))
    (X0 LOAD X1 ON TOP OF X2)
    \-~->
    (pk x0 x1 t2 x1 x2))
  ((("00008-000439-000002-watering-pot"
      "person put watering-pot in trunk on box"))
    (X0 PUT X1 IN TRUNK ON X2)
    \-~->
    (pk x0 x1 t2 x1 x2))
  ((("00008-000449-000002-watering-pot"
      "person take watering-pot off of box put it on ground"))
    (X0 TAKE X1 OFF OF X2 PUT IT ON GROUND)
    \-~->
    (pd x0 x1 t1 x1 x2))
  ((("00008-000449-000002-watering-pot" "person unload watering-pot to ground")
     ("00008-000637-000002-gas-can" "person unload gas-can to ground"))
    (X0 UNLOAD X1 TO GROUND)
    \-~->
    (pd x0 x1))
  ((("00008-000449-000002-watering-pot"
      "person take watering-pot from trunk put it on ground"))
    (X0 TAKE X1 FROM TRUNK PUT IT ON GROUND)
    \-~->
    (pd x0 x1))
  ((("00008-000603-000003-watering-pot"
      "person put watering-pot into bucket in trunk"))
    (X0 PUT X1 INTO X2 IN TRUNK)
    \-~->
    (pk x0 x1 t2 x1 x2))
  ((("00008-000603-000003-watering-pot"
      "person pick up watering-pot stack it on top of bucket"))
    (X0 PICK UP X1 STACK IT ON TOP OF X2)
    \-~->
    (pk x0 x1 t2 x1 x2))
  ((("00008-000603-000003-watering-pot"
      "person put watering-pot on top of bucket in trunk"))
    (X0 PUT X1 ON TOP OF X2 IN TRUNK)
    \-~->
    (pk x0 x1 t2 x1 x2))
  ((("00008-000640-000003-bucket"
      "person take bucket out of trunk put it near gas-can")
     ("00008-000644-000002-watering-pot"
       "person take watering-pot out of trunk put it near bucket"))
    (X0 TAKE X1 OUT OF TRUNK PUT IT NEAR X2)
    \-~->
    (pd x0 x1 n2 x1 x2))
  ((("00008-000640-000003-bucket" "person unload bucket put it near gas-can"))
    (X0 UNLOAD X1 PUT IT NEAR X2)
    \-~->
    (pd x0 x1 n2 x1 x2))
  ((("00008-000644-000002-watering-pot"
      "person pick up watering-pot put it near bucket"))
    (X0 PICK UP X1 PUT IT NEAR X2)
    \-~->
    (pk x0 x1 n2 x1 x2)))
