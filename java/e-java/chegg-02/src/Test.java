
public class Test {

	public static void main(String[] args) {
		Baby baby = new Baby();
		baby.setDiaperCount(9);
		baby.isPooping();
		baby.isPeeing();
		if(baby.isCrying()) {
			while(!baby.isFull()) {
				baby.isEating();
			}
			baby.setDiaperChanged();
		}
		System.out.println("Daily eat count = "+baby.getDailyEatCount());
		System.out.println("Diaper count = "+baby.getDiaperCount());
		System.out.println("Eat count = "+baby.getEatCount());
		System.out.println("Peer count = "+baby.getPeeCount());
		System.out.println("Poop count = "+baby.getPoopCount());
	}

}
