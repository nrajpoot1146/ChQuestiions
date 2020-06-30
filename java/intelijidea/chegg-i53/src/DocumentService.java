import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class DocumentService implements DocumentRepository{

    // list to store documents
    static ArrayList<Document> documentRepository = new ArrayList<Document>();

    /**
     * read data from document.txt and store it into document repository
     */
    DocumentService(){
        File f = new File("document.txt");
        try {
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(new FileInputStream(f)));
            String line = "";
            while ( (line = bufferedReader.readLine()) != null && line != ""){
                String[] data = line.split(";");
                int docId = Integer.parseInt(data[0]);
                int catId = Integer.parseInt(data[1]);
                int topId = Integer.parseInt(data[2]);
                String tags = data[3];
                String filename = data[4];
                Document document = new Document(docId, catId, topId, tags, filename);
                documentRepository.add(document);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * get document by document id
     * @param documentId
     * @return
     */
    @Override
    public Document findById(int documentId) {
        for (Document doc : documentRepository){
            if (doc.getDocumentId() == documentId){
                return doc;
            }
        }
        return null;
    }

    /**
     * find list of documents by topic id
     * @param topicId
     * @return list of documents
     */
    @Override
    public List findByTopicId(String topicId) {
        ArrayList<Document> list = new ArrayList<Document>();
        for (Document doc : documentRepository){
            if (doc.getTopicId() == Integer.parseInt(topicId)){
                list.add(doc);
            }
        }
        return list;
    }

    /**
     * find list of documents by category id
     * @param categoryId
     * @return
     */
    @Override
    public List findByCategoryId(String categoryId) {
        ArrayList<Document> list = new ArrayList<Document>();
        for (Document doc : documentRepository){
            if (doc.getTopicId() == Integer.parseInt(categoryId)){
                list.add(doc);
            }
        }
        return list;
    }

    /**
     * find list of documents by tags
     * @param tags
     * @return
     */
    @Override
    public List findByTags(List tags) {
        ArrayList<Document> list = new ArrayList<Document>();
        for (Document doc : documentRepository){
            for (int i = 0; i < tags.size(); i++){
                if (doc.getTags().contains((String)tags.get(i))){
                    list.add(doc);
                    break;
                }
            }
        }
        return list;
    }

    /**
     * find list of documents by file name
     * @param fileName
     * @return
     */
    @Override
    public List findByFileName(String fileName) {
        ArrayList<Document> list = new ArrayList<Document>();
        for (Document doc : documentRepository){
            if (doc.getFilename().equals(fileName)){
                list.add(doc);
            }
        }
        return list;
    }

    public static void main(String[] args){
        DocumentService documentService = new DocumentService();

        System.out.println("Find by id: ");
        System.out.println(documentService.findById(1).toString());

        System.out.println("Find By tags");
        List tags = new LinkedList<String>();
        tags.add("Syllabus");
        System.out.println(documentService.findByTags(tags).toString());
    }
}
