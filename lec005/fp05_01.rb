Pixel = Struct.new(:r, :g, :b)
$img = Array.new(200) do
  Array.new(300) do Pixel.new(255,255,255) end
end

def pset(x,y,r,g,b)
  if 0 <= x && x < 300 && 0 <= y && y < 200
    $img[y][x].r = r; $img[y][x].g = g; $img[y][x].b = b
  end
end

def writeimage(name)
  open(name, "wb") do |f|
    f.puts("P6\n300 200\n255")
    $img.each do |a|
      a.each do |p| f.write(p.to_a.pack("ccc")) end
    end
  end
end

def mypicture
  pset(100, 80, 255, 0, 0)
  writeimage("img/t.ppm")
end

def mypicture2
  80.step(120) do |x| pset(x, 80, 0, 0, 255) end
  writeimage("img/t.ppm")
end

=begin
a. 水平はもうわかったので、垂直または斜め (右上がり) に線を引くようにしてみる。
=end
def a
  begin
    x = 80
    # 垂直
    80.step(120) do |y| pset(x, y, 0, 0, 255) end
    80.step(120) do |y|
      pset(x, y, 0, 0, 255)
      x -= 1
    end
    writeimage("img/a.ppm")
    return true
  rescue => e
    return e
  end
end

=begin
b. 線が細いと弱っちいので、幅 3 の線を引くようにしてみる (ヒント: (x, 79),(x, 80),(x, 81)
に点を打つなどする)。
=end
def b
  begin
    for i in 79..80 do
      80.step(120){|y| pset(i, y, 0, 0, 255 ) }
    end
    writeimage("img/b.ppm")
    return true
  rescue => e
    return e
  end
end

=begin
c. 線を複数使って、長方形とか正方形を描く。
=end
def c
  begin
    # 正方形
    for x in 80..120 do
      for y in 80..120 do
        if (80 <= x && x <= 82) || (118 <= x && x <= 120) ||
          (80 <= y && y <= 82) || (118 <= y && y <= 120) then
          pset(x, y, 0, 0, 255 )
        end
      end
    end
    # 長方形
    for x in 150..230 do
      for y in 80..120 do
        if (150 <= x && x <= 152) || (228 <= x && x <= 230) ||
          (80 <= y && y <= 82) || (118 <= y && y <= 120) then
          pset(x, y, 0, 0, 255 )
        end
      end
    end
    writeimage("img/c.ppm")
    return true
  rescue => e
    return e
  end
end

=begin
d. 長方形とか正方形の中を塗りつぶす (ヒント: x 方向だけに繰り返したら水平線だが、それ
をさらに y 方向に繰り返すと四角い領域の中全部が塗れる)。
=end
def d
  begin
    # 正方形
    for x in 80..120 do
      for y in 80..120 do
        pset(x, y, 0, 0, 255 )
      end
    end
    # 長方形
    for x in 0..80 do
      for y in 0..40 do
        pset(x, y, 0, 0, 255 )
      end
    end
    writeimage("img/d.ppm")
    return true
  rescue => e
    return e
  end
end

=begin
e. 三角形を描いてみる (塗りつぶすのは多少工夫が必要かと)。
=end
def e
  begin
    #for x in 80..120 do
    #  pset(x, 200, 0, 0, 255 )
    #end
    x1 = 150
    x2 = 150
    for y in 50..150 do
      for x in 150..x1 do
        pset(x, y, 0, 0, 255 )
      end
      for x in x2..150 do
        pset(x, y, 0, 0, 255 )
      end
      if(y % 2 == 0) then
        x1 += 1
        x2 -= 1
      end
    end
    writeimage("img/e.ppm")
    return true
  rescue => e
    return e
  end
end

=begin
f. その他、好きな図形や模様や色を表現してみる。
=end
def f
  begin
  rescue => e
    return e
  end
end
