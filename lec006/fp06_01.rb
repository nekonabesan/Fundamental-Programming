require __dir__ + '/../modules/fp_image.rb'
=begin
処理の中でオブジェクトを生成する実装例
※実装は煩雑だが処理固有のオブジェクトを定義できる
=end
def a
  begin
    obj = FpImage.new
    #
    obj.rectangle(150,100,300,200,67,135,233)
    #
    obj.rectangle(150,160,300,80,171,255,127)
=begin
  背景の山
=end
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(150,30,-80,120,200,120,255,255,255)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(200,30,0,120,300,120,86,99,143)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(40,20,-40,120,80,120,231,232,226)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(260,20,180,120,360,120,231,232,226)
    # ellipse(x0, y0, prm_a, prm_b, r, g, b)
=begin
  湖
=end
    obj.ellipse(100,160,60,20,0,0,255)
    obj.ellipse(0,180,120,40,0,0,255)
=begin
  木
=end
    # Tree Obj01
    # rectangle(x, y, w, h, r, g, b)
    obj.rectangle(40,110,4,40,93,93,33)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(40,30,30,70,50,70,47,79,54)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(40,50,35,90,55,90,47,79,54)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(40,80,40,110,60,110,47,79,54)
    # Tree Obj01
    # rectangle(x, y, w, h, r, g, b)
    obj.rectangle(10,110,4,40,93,93,33)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(10,30,0,70,20,70,47,79,54)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(10,50,-5,90,15,90,47,79,54)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(10,80,-10,110,20,110,47,79,54)
    # Tree Obj01
    # rectangle(x, y, w, h, r, g, b)
    obj.rectangle(30,110,4,40,93,93,33)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(30,30,20,70,40,70,47,79,54)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(30,60,15,90,45,90,47,79,54)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(30,80,10,110,50,110,47,79,54)
    # Tree Obj01
    # rectangle(x, y, w, h, r, g, b)
    obj.rectangle(50,115,4,40,93,93,33)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(50,35,40,75,60,75,68,160,119)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(50,55,35,95,65,95,68,160,119)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(50,75,30,115,70,115,68,160,119)
    # Tree Obj01
    # rectangle(x, y, w, h, r, g, b)
    obj.rectangle(20,120,4,40,93,93,33)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(20,40,10,80,30,80,81,178,76)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(20,60,5,100,35,100,81,178,76)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(20,80,0,120,40,120,81,178,76)
    # Tree Obj01
    # rectangle(x, y, w, h, r, g, b)
    obj.rectangle(250,115,4,35,93,93,33)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(250,35,240,75,260,75,44,82,60)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(250,55,235,95,265,95,44,82,60)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(250,75,230,115,270,115,44,82,60)
    # Tree Obj01
    # rectangle(x, y, w, h, r, g, b)
    obj.rectangle(240,120,4,40,93,93,33)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(240,40,230,80,250,80,47,79,54)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(240,60,225,100,255,100,47,79,54)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(240,80,220,120,260,120,47,79,54)
    # Tree Obj01
    # rectangle(x, y, w, h, r, g, b)
    obj.rectangle(290,140,4,40,93,93,33)
    # ellipse(x0, y0, prm_a, prm_b, r, g, b)
    obj.ellipse(290,80,20,50,51,96,69)
    # Tree Obj01
    # rectangle(x, y, w, h, r, g, b)
    obj.rectangle(270,150,4,40,124,96,53)
    # ellipse(x0, y0, prm_a, prm_b, r, g, b)
    obj.ellipse(270,90,20,40,81,178,76)
    # Tree Obj01
    # rectangle(x, y, w, h, r, g, b)
    obj.rectangle(280,160,4,40,124,96,53)
    # ellipse(x0, y0, prm_a, prm_b, r, g, b)
    obj.ellipse(280,100,20,40,11,218,81)
=begin
 家の描画
=end
    # rectangle(x, y, w, h, r, g, b)
    obj.rectangle(220,120,20,80,127,37,9)
    # rectangle(x, y, w, h, r, g, b)
    obj.rectangle(200,150,82,52,0,0,0)
    # rectangle(x, y, w, h, r, g, b)
    obj.rectangle(200,150,80,50,255,249,177)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(200,90,150,130,250,130,255,0,0)
    # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    obj.triangle(200,100,160,130,240,130,255,249,177)
    # rectangle(x, y, w, h, r, g, b)
    obj.rectangle(185,145,40,30,132,90,18)
    # rectangle(x, y, w, h, r, g, b)
    obj.rectangle(176,145,16,26,211,237,251)
    # rectangle(x, y, w, h, r, g, b)
    obj.rectangle(194,145,16,26,211,237,251)

    # rectangle(x, y, w, h, r, g, b)
    obj.rectangle(225,150,20,40,132,90,18)


    obj.writeimage("img/6a.ppm")
    return true
  rescue => e
    return e
  end
end
