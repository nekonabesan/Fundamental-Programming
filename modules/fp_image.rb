class FpImage

  def initialize
    @Pixel = Struct.new(:r, :g, :b)
    @img = Array.new(200) do
      Array.new(300) do @Pixel.new(255,255,255) end
    end
  end

  def pset(x,y,r,g,b)
    if 0 <= x && x < 300 && 0 <= y && y < 200
      @img[y][x].r = r; @img[y][x].g = g; @img[y][x].b = b
    end
  end

  def writeimage(name)
    open(name, "wb") do |f|
      f.puts("P6\n300 200\n255")
      @img.each do |a|
        a.each do |p| f.write(p.to_a.pack("ccc")) end
      end
    end
  end

  def fillcircle(x0, y0, rad, r, g, b)
    begin
      200.times do |y|
        300.times do |x|
          if (x-x0)**2 + (y-y0)**2 <= rad**2 then pset(x, y, r, g, b) end
        end
      end
    rescue => e
      return e
    end
  end

  def ellipse(x0, y0, prm_a, prm_b, r, g, b)
    begin
      200.times do |y|
        300.times do |x|
          if (((x-x0).to_f**2)/(prm_a.to_f**2)) + (((y-y0).to_f**2)/(prm_b.to_f**2)) <= 1.0 then
            pset(x, y, r, g, b)
          end
        end
      end
    rescue => e
      return e
    end
  end

  def triangle(x0, y0, x1, y1, x2, y2, r, g, b)
    begin
      200.times do |y|
        300.times do |x|
          if (x1 - x0)*(y - y0) - (y1 - y0)*(x - x0) <= 0 && (x2 - x0)*(y - y0) - (y2 - y0)*(x - x0) >= 0 && (x2 - x1)*(y - y1) - (y2 - y1)*(x - x1) <= 0 then
            pset(x, y, r, g, b)
          end
        end
      end
      return true
    rescue => e
      return e
    end
  end

  def rectangle(x, y, w, h, r, g, b)
    j0 = (y - 0.5 * h).to_i
    j1 = (y + 0.5 * h).to_i
    i0 = (x - 0.5 * w).to_i
    i1 = (x + 0.5 * w).to_i
    j0.step(j1) do |j|
      i0.step(i1) do |i| pset(i, j, r, g, b) end
    end
  end
end
