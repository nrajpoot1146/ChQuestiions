import java.util.List;

public interface DocumentRepository {
    Document findById(int documentId);
    List findByTopicId(String topicId);
    List findByCategoryId(String categoryId);
    List findByTags(List tags);
    List findByFileName(String fileName);

}