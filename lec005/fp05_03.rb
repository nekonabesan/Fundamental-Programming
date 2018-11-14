require __dir__ + '/../modules/fp_image.rb'

=begin
a. ドーナツ型を塗るメソッド。4
=end
def a
  begin
    obj = FpImage.new
    # 一度塗りつぶす
    obj.fillcircle(100,100,90,39,38,144)
    # 中心部分を白で塗りつぶす
    obj.fillcircle(100,100,70,255,255,255)
    obj.writeimage("img/3a.ppm")
    return true
  rescue => e
    return e
  end
end

=begin
b. 長方形または楕円を塗るメソッド。
=end
def b
  begin
    obj = FpImage.new
    obj.ellipse(150,100,40,20,0,0,255)
    obj.writeimage("img/3b.ppm")
    return true
  rescue => e
    return e
  end
end

=begin
c. 三角形を塗るメソッド。
=end
def c
  begin
    obj = FpImage.new
    obj.triangle(150,50,100,150,200,150,0,0,255)
    obj.writeimage("img/3c.ppm")
    return true
  rescue => e
    return e
  end
end

=begin
d. その他、自分の好きな形を塗るメソッド。
=end
def d
  begin
    obj = FpImage.new
    obj.rectangle(100,110,100,20,0,0,255)
    obj.writeimage("img/3d.ppm")
    return true
  rescue => e
    return e
  end
end
