require __dir__ + "/spec_helper"
require __dir__ + '/../fp02_06.rb'

describe "演習6" do
  it "p(0)" do
    obj = Fp02_06.new
    results = obj.p(0)
    expect(results).to be_a(ArgumentError)
  end
  it "p(1)" do
    obj = Fp02_06.new
    results = obj.p(1)
    expect(results).to eq true
  end
  it "p(2)" do
    obj = Fp02_06.new
    results = obj.p(2)
    expect(results).to eq true
  end
  it "p(3)" do
    obj = Fp02_06.new
    results = obj.p(3)
    expect(results).to eq true
  end
  it "p(4)" do
    obj = Fp02_06.new
    results = obj.p(4)
    expect(results).to eq false
  end
  it "p(5)" do
    obj = Fp02_06.new
    results = obj.p(5)
    expect(results).to eq true
  end
  it "p(6)" do
    obj = Fp02_06.new
    results = obj.p(6)
    expect(results).to eq false
  end
  it "p(7)" do
    obj = Fp02_06.new
    results = obj.p(7)
    expect(results).to eq true
  end
  it "p(11)" do
    obj = Fp02_06.new
    results = obj.p(11)
    expect(results).to eq true
  end
  it "p(1229)" do
    obj = Fp02_06.new
    results = obj.p(1229)
    expect(results).to eq true
  end
  it "p(3432)" do
    obj = Fp02_06.new
    results = obj.p(3432)
    expect(results).to eq false
  end
  it "p(3433)" do
    obj = Fp02_06.new
    results = obj.p(3433)
    expect(results).to eq true
  end
  it "p(3434)" do
    obj = Fp02_06.new
    results = obj.p(3434)
    expect(results).to eq false
  end
  it "p(3449)" do
    obj = Fp02_06.new
    results = obj.p(3449)
    expect(results).to eq true
  end
  it "p(3457)" do
    obj = Fp02_06.new
    results = obj.p(3457)
    expect(results).to eq true
  end
  it "p(nil)" do
    obj = Fp02_06.new
    results = obj.p(nil)
    expect(results).to be_a(ArgumentError)
  end
  it "p(0)" do
    obj = Fp02_06.new
    results = obj.p(0)
    expect(results).to be_a(ArgumentError)
  end
end
